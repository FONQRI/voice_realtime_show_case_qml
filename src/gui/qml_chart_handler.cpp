#include "qml_chart_handler.h"

#include "../audio/x_y__series_io_device.h"
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>

#include <QDebug>

qml_chart_handler::qml_chart_handler(QObject *root_object, QObject *parent)
	: QObject(parent)
{
	auto item = root_object->findChild<QObject *>("chart_view");
	if (!item)
	{
		qDebug() << "ops";
	}

	QObject::connect(item, SIGNAL(init_chart(QVariant, QVariant, QVariant)),
			 this, SLOT(init_chart(QVariant, QVariant, QVariant)));
}

qml_chart_handler::~qml_chart_handler()
{
	m_audioInput->stop();
	m_device->close();
}

void qml_chart_handler::init_chart(const QVariant &axisX, const QVariant &axisY,
				   const QVariant &line_series)
{

	QLineSeries *m_series =
	qobject_cast<QLineSeries *>(line_series.value<QObject *>());

	QValueAxis *m_axisX = qobject_cast<QValueAxis *>(axisX.value<QObject *>());
	m_axisX->setRange(0, 2000);
	m_axisX->setLabelFormat("%g");
	m_axisX->setTitleText("Samples");
	QValueAxis *m_axisY = qobject_cast<QValueAxis *>(axisY.value<QObject *>());
	m_axisY->setRange(-1, 1);
	m_axisY->setTitleText("Audio level");

	QAudioFormat formatAudio;
	formatAudio.setSampleRate(8000);
	formatAudio.setChannelCount(1);
	formatAudio.setSampleSize(8);
	formatAudio.setCodec("audio/pcm");
	formatAudio.setByteOrder(QAudioFormat::LittleEndian);
	formatAudio.setSampleType(QAudioFormat::UnSignedInt);

	QAudioDeviceInfo inputDevices = QAudioDeviceInfo::defaultInputDevice();
	m_audioInput = new QAudioInput(inputDevices, formatAudio, this);
	m_series->append(QPointF(0, 0));
	m_series->append(QPointF(5, 10));
	m_device = new x_y__series_io_device(m_series, this);
	m_device->open(QIODevice::WriteOnly);

	m_audioInput->start(m_device);
}
