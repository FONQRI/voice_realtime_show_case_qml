#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>
#include <QtWidgets/QApplication>

#include "gui/qml_chart_handler.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	// Qt Charts uses Qt Graphics View Framework for drawing, therefore
	// QApplication must be used.
	QApplication app(argc, argv);

	QQuickView viewer;

	// The following are needed to make examples run without having to install
	// the module in desktop environments.
#ifdef Q_OS_WIN
	QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
	QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
	viewer.engine()->addImportPath(extraImportPath.arg(
	QGuiApplication::applicationDirPath(), QString::fromLatin1("qml")));
	QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer,
			 &QWindow::close);

	viewer.setTitle(QStringLiteral("QML Axes"));
	viewer.setSource(QUrl("qrc:/main.qml"));
	viewer.setResizeMode(QQuickView::SizeRootObjectToView);
	viewer.show();

	qml_chart_handler m_qml_chart_handler(&viewer);

	return app.exec();
}
