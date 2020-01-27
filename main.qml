import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Window 2.3
import QtCharts 2.0

Item {
    visible: true
    width: 640
    height: 480
    AudioChartView{

    }


//        ChartView {
//            id: chartView
//            anchors.fill: parent
//            theme: ChartView.ChartThemeBrownSand
//            antialiasing: true

//            LineSeries {
//                name: "LineSeries"
//                XYPoint { x: 0; y: 0 }
//                XYPoint { x: 1.1; y: 2.1 }
//                XYPoint { x: 1.9; y: 3.3 }
//                XYPoint { x: 2.1; y: 2.1 }
//                XYPoint { x: 2.9; y: 4.9 }
//                XYPoint { x: 3.4; y: 3.0 }
//                XYPoint { x: 4.1; y: 3.3 }
//            }

//            MouseArea{
//                anchors.fill: parent
////                onDoubleClicked: chartView.zoomReset();
//                onDoubleClicked: {
//                    var r = Qt.rect(0,100,20,20)
//                    chartView.zoomIn(r)
//                }
//            }

//            PinchArea{
//                id: pa
//                anchors.fill: parent
//                onPinchUpdated: {
//                    chartView.zoomReset();
//                    var center_x = pinch.center.x
//                    var center_y = pinch.center.y
//                    var width_zoom = height/pinch.scale;
//                    var height_zoom = width/pinch.scale;
//                    var r = Qt.rect(center_x-width_zoom/2, center_y - height_zoom/2, width_zoom, height_zoom)
//                    chartView.zoomIn(r)
//                }


//        }
//    }


    

}
