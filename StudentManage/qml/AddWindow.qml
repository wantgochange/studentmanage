import QtQuick 2.0

Item {
    width: 1920/3
    height: 1080/3
    property string alertTxt_top_text_set: ""
    property string alertTxt_bottom_text_set: ""
    property alias alertTxt_top_mouse: alertTxt_top_mouse
    property alias alertTxt_bottom_mouse: alertTxt_bottom_mouse
    Rectangle{
        id:alertTxt
        radius: 3
        height: 228*2/3
        width: (23+618+35)/3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        border.color: "gray"
        border.width: 0.5
        color: "#fff"

        Rectangle{
            anchors.fill: parent
            color: "#000"
            opacity: 0.3
        }

        Rectangle{
            id:alertTxt_top
            anchors.top:parent.top
            anchors.left: parent.left
            width: parent.width
            height: parent.height/2
            color: "#fff"
            Text {
                id: alertTxt_top_text
                text: alertTxt_top_text_set
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.pixelSize: 60/3
            }
            MouseArea{
                id:alertTxt_top_mouse
                anchors.fill: parent
                onClicked: {

                }
                onPressed: {
                    alertTxt_top.color = "#238640"
                    alertTxt_top_text.color = "#fff"
                }
                onReleased: {
                    alertTxt_top.color = "#fff"
                    alertTxt_top_text.color = "black"
                }
            }
        }



        Rectangle{
            id:alertTxt_bottom
            anchors.bottom:parent.bottom
            anchors.left: parent.left
            width: parent.width
            height: parent.height/2
            color: "#fff"
            Text {
                id: alertTxt_bottom_text
                text: alertTxt_bottom_text_set
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.pixelSize: 60/3
            }
            MouseArea{
                id:alertTxt_bottom_mouse
                anchors.fill: parent
                onClicked: {

                }
                onPressed: {
                    alertTxt_bottom.color = "#238640"
                    alertTxt_bottom_text.color = "#fff"
                }
                onReleased: {
                    alertTxt_bottom.color = "#fff"
                    alertTxt_bottom_text.color = "black"
                }
            }
        }
        Mline{
            width: 618/3
            anchors.left: parent.left
            anchors.leftMargin: 23/3
            anchors.top:alertTxt_top.bottom
            color: "gray"
        }

    }
}
