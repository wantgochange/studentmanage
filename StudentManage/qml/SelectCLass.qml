import QtQuick 2.0

Item {
    width: 360
    height: 587
    Rectangle{
        anchors.fill: parent
        Image{
            anchors.fill: parent
            source: "./../images/bg.png"
        }
        Rectangle{
            anchors.top:parent.top
            anchors.topMargin: mainRoot.height/2 - 80
            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 120
//            color: "black"
            opacity: 0.5
            radius: 10
            Item{
                id:select_Item_student
                height: parent.height/2
                width: parent.width
                anchors.top:parent.top
                anchors.left: parent.left
                Text {
                    id: student_class
                    text: qsTr("学生信息")
                    color: "white"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        mainstack.permissions = false
                        mainstack.push("qrc:/qml/PersonList.qml")
                    }
                    onPressed: {
                        student_class.color= "green"
                    }
                    onReleased: {
                        student_class.color= "white"
                    }
                }
            }
            Rectangle{
                color: "black"
                anchors.top:select_Item_student.bottom
                height: 1
                width: parent.width - 10
                anchors.left: parent.left
                anchors.leftMargin: 5
            }

            Item{
                id:select_Item_teach
                height: parent.height/2
                width: parent.width
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                Text {
                    id: teach_class
                    text: qsTr("教师信息（管理员权限）")
                    color: "white"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("=================-")
                        mainstack.permissions = true
                        mainstack.push("qrc:/qml/PersonList.qml")
                    }
                    onPressed: {
                        teach_class.color= "green"
                    }
                    onReleased: {
                        teach_class.color= "white"
                    }
                }
            }

        }
    }

}
