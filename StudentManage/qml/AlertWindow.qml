import QtQuick 2.0

Item {
    width: 1920/3
    height: 1080/3
    property string content_text_set: ""
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
        Text {
            id: content_text
            text: content_text_set
            anchors.centerIn: parent
            color: "black"
            font.pixelSize: 60/3
        }

    }
}
