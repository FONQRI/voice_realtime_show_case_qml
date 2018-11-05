import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Window 2.3
import QtCharts 2.2
import QtQuick 2.0
import QtCharts 2.0

Item {
    visible: true
    width: 640
    height: 480

    //![1]
    ChartView {
        id:chart_view
        title: "Two Series, Common Axes"
        anchors.fill: parent
                    legend.visible: false
        antialiasing: true
        objectName: "chart_view"

        signal init_chart(var x_axis ,var y_axis ,var sries)


        Timer{
            interval: 1000
            running: true
            repeat: false
            onTriggered: chart_view.init_chart(axisX,axisY,series)
        }

        ValueAxis {
            id: axisX
            min: 0
            max: 10
            tickCount: 5
        }

        ValueAxis {
            id: axisY
            min: -0.5
            max: 1.5
        }

        LineSeries {
            id: series
            axisX: axisX
            axisY: axisY
        }


    }

    //    // Add data dynamically to the series
    //    Component.onCompleted: {
    //        for (var i = 0; i <= 10; i++) {
    //            series1.append(i, Math.random());
    //            series2.append(i, Math.random());
    //        }
    //    }
    //![1]


}
