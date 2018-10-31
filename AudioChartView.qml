import QtQuick 2.9
import QtCharts 2.2

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
