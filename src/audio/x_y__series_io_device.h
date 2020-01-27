#ifndef X_Y_SERIES_IO_DEVICE_H
#define X_Y_SERIES_IO_DEVICE_H

#include <QtCharts/QChartGlobal>
#include <QtCore/QIODevice>

QT_CHARTS_BEGIN_NAMESPACE
class QXYSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class x_y_series_io_device : public QIODevice {
	Q_OBJECT
  public:
	explicit x_y_series_io_device(QXYSeries *series, QObject *parent = 0);

  protected:
	qint64 readData(char *data, qint64 maxSize);
	qint64 writeData(const char *data, qint64 maxSize);

  private:
	QXYSeries *m_series;
};

#endif // X_Y__SERIES_IO_DEVICE_H
