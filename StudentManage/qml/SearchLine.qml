import QtQuick 2.0

Rectangle {
    id: searchLine
    anchors.top:parent.top
    color:"#3a3b23"
    width: parent.width; height: 42
//    radius: 4
    signal signalgetinputtext(string text)
    signal signalgetfocus(bool inputfocus)
    property alias inputtext: input
    BorderImage {
        anchors.centerIn: parent
        width: parent.width - 10; height: 24
        Item {
            visible: !input.activeFocus && !input.text.length
            anchors.centerIn: parent
//            anchors.horizontalCenterOffset: -40
            Image {
                id: searchIcon
//                anchors.verticalCenter: parent.verticalCenter
//                anchors.horizontalCenter: parent.horizontalCenter
                anchors.centerIn: parent
                source: "./../images/person_image/query_icon.png"
                height: 20
                width: 70
            }
//            Text {
//                anchors.verticalCenter: parent.verticalCenter
//                anchors.left: searchIcon.right
//                anchors.leftMargin: 16
//                font.pixelSize: 30
//                color: "#707070"
//                text:"搜索"
//                horizontalAlignment:Qt.AlignHCenter
//            }
        }
        TextInput {
            id: input
            anchors.fill: parent
            verticalAlignment: Qt.AlignVCenter
            horizontalAlignment: Qt.AlignHCenter
            clip: true
            color: "#707070"
            font.pixelSize: 15
            onTextChanged: {
                signalgetinputtext(input.text)
            }
            onFocusChanged: {
                if(input.focus){
//                    toolBar.visible = false
//                    toolBar.height = 0;
                    signalgetfocus(true)
                }
                else{
//                    toolBar.visible = true
//                    toolBar.height = 150;
                    input.text = ""
                }
            }
        }
    }
}
