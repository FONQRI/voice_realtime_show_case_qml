#include "x_y__series_io_device.h"
#include <QtCharts/QXYSeries>

x_y__series_io_device::x_y__series_io_device(QXYSeries *series, QObject *parent)
	: QIODevice(parent), m_series(series)
{
}

qint64 x_y__series_io_device::readData(char *data, qint64 maxSize)
{
	Q_UNUSED(data)
	Q_UNUSED(maxSize)
	return -1;
}

qint64 x_y__series_io_device::writeData(const char *data, qint64 maxSize)
{
	qint64 range = 2000;
	QVector<QPointF> oldPoints = m_series->pointsVector();
	QVector<QPointF> points;
	int resolution = 4;

	if (oldPoints.count() < range) {
		points = m_series->pointsVector();
	}
	else {
		for (int i = maxSize / resolution; i < oldPoints.count(); i++)
		points.append(
			QPointF(i - maxSize / resolution, oldPoints.at(i).y()));
	}

	qint64 size = points.count();
	for (int k = 0; k < maxSize / resolution; k++)
	points.append(
		QPointF(k + size, ((quint8)data[resolution * k] - 128) / 128.0));

	m_series->replace(points);
	return maxSize;
}
