import QtQuick 2.7
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3

ToolBar {
    id: menu
    property alias teacher_item: teacher_item
    property alias person_item: person_item
    property alias group_item: group_item

    property bool direction: false

    property bool bIsPerson: false
    property bool bIsGroup: false
    property bool bIsteacher: false

    anchors.bottom: parent.bottom

//    Component {
        Image {
            width: 360
            fillMode: Image.Tile
            anchors.left: parent.left
            anchors.leftMargin: -20
            anchors.right: parent.right
            anchors.rightMargin: -20
            anchors.top:parent.top
            anchors.topMargin: -5
            source: "./../images/person_image/bg.png"
            opacity:0.9
        }
//    }
    RowLayout{
        anchors.fill: parent
        spacing: 10
        Item {
            id: teacher_item
            Layout.leftMargin: 5
            Layout.preferredWidth:94
            Layout.preferredHeight: 48

            Text {
                id: teacher_txt
                text: "教"
                font.pointSize: 30
                color:bIsteacher ? "white" : "#238640"
                anchors.centerIn: parent
            }


            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(!bIsteacher)
                    {
                        mainstack.push("qrc:/qml/TeacherList.qml")
                    }
                }
                onPressed: {
                    if(!bIsteacher)
                    {
                        teacher_txt.color = "#238640"
                    }
                }
                onReleased: {
                    if(!bIsteacher)
                    {
                        teacher_txt.color = "white"
                    }
                }
            }
        }
        Item {
            id: person_item
            Layout.leftMargin: 16
            Layout.preferredWidth:94
            Layout.preferredHeight: 48
            Text {
                id: person_txt
                text: "学"
                font.pointSize: 30
                color: bIsPerson ? "white" : "#238640"
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(!bIsPerson)
                    {
                        mainstack.push("qrc:/qml/PersonList.qml")
                    }
                }

                onPressed: {
                    if(!bIsPerson)
                    {
                        person_txt.color = "#238640"
                    }
                }
                onReleased: {
                    if(!bIsPerson)
                    {
                        person_txt.color = "white"
                    }
                }
            }
        }
        Item {
            id: group_item
            Layout.leftMargin: 16
            Layout.preferredWidth:94
            Layout.preferredHeight: 48
            Text {
                id: group_txt
                text: "班"
                font.pointSize: 30
                color: bIsGroup ? "white" : "#238640"
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(!bIsGroup)
                    {
                        mainstack.push("qrc:/qml/GroupList.qml")
                    }
                }

                onPressed: {
                    if(!bIsGroup)
                    {
                        group_txt.color = "#238640"
                    }
                }
                onReleased: {
                    if(!bIsGroup)
                    {
                        group_txt.color = "white"
                    }
                }
            }
        }

    }


}
