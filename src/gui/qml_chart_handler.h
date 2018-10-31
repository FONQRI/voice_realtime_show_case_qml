#ifndef QML_CHART_HANDLER_H
#define QML_CHART_HANDLER_H

#include <QObject>

#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class x_y__series_io_device;

QT_BEGIN_NAMESPACE
class QAudioInput;
QT_END_NAMESPACE

class qml_chart_handler : public QObject {
	Q_OBJECT
  public:
	explicit qml_chart_handler(QObject *root_object, QObject *parent = nullptr);
	~qml_chart_handler();

  signals:

  public slots:
	void init_chart(const QVariant &axisX, const QVariant &axisY,
			const QVariant &line_series);

  private:
	x_y__series_io_device *m_device;
	QChart *m_chart;
	QAudioInput *m_audioInput;
};

#endif // QML_CHART_HANDLER_H
