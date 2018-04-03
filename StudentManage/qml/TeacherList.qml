import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Item
{
    visible: true
    width: 360
    height: 587

    Image
    {
        id: backgroundImage
        width: parent.width
        height: parent.height
        source: "./../images/person_image/bg.png"
        fillMode: Image.TileHorizontally

        //编辑界面
        Item
        {
            id: editorItem
            width: parent.width
            height: 176 / 3
            anchors.top: parent.top

            Image
            {
                id: editorImage
                width: 156 / 3
                height: 156 / 3
                anchors.right: parent.right
                anchors.rightMargin: 10 / 3
                anchors.top: parent.top
                anchors.topMargin: 10 / 3
                source: "./../images/callRecord/editor.png"
                visible: mainstack.permissions
                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {
                         console.log("教师添加")
                        mainstack.push("qrc:/qml/TeacherListInformation.qml")
                    }

                    onPressed:
                    {
                        editorImage.source = "./../images/callRecord/editor-click.png"
                    }
                    onReleased:
                    {
                        editorImage.source = "./../images/callRecord/editor.png"
                    }
                }
            }
        }

        //bottom UI
        Image
        {
            id: bottomImage
            width: parent.width
            height: 1517 / 3
            anchors.top: editorItem.bottom
            source: "./../images/callRecord/bottom_bg_02.png"
            Item
            {
                id: listViewItem
                width: 1000 / 3
                height: 1389 / 3
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top

                ListModel
                {
                    id: listModel
                    ListElement
                    {
                        activeState: "./../images/callRecord/answerPhone.png"
                        contactName: "安一"
                        position: "语文"
                        dataTime: "3月1日"
                        talkTime: "14:22"
                    }
                    ListElement
                    {
                        activeState: "./../images/callRecord/havePhone.png"
                        contactName: "安2"
                        position: "数学"
                        dataTime: "3月1日"
                        talkTime: "14:22"
                    }
                    ListElement
                    {
                        activeState: "./../images/callRecord/answerPhone.png"
                        contactName: "安3"
                        position: "英语"
                        dataTime: "3月1日"
                        talkTime: "14:22"
                    }
                    ListElement
                    {
                        activeState: "./../images/callRecord/notCall.png"
                        contactName: "安4"
                        position: "体育"
                        dataTime: "3月1日"
                        talkTime: "14:22"
                    }
                }


                Component
                {
                    id: delegate
                    Rectangle
                    {
                        width: 1040 / 3
                        height: 179 / 3
                        color: "#777857"
                        radius: 20 /3
                        //老师照片
                        Image
                        {
                            id: callStateImage
                            source: "./../images/person_image/headpic_icon.png"
                            width: 120 / 3
                            height: 120 / 3
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 30 / 3
                        }

                        //姓名
                        Text
                        {
                            id: contactNameText
                            anchors.left: callStateImage.right
                            anchors.leftMargin: 20 / 3
                            anchors.top: parent.top
                            anchors.topMargin: 22 / 3
                            text: contactName
                            color: "#ffffff"
                            font.pointSize: 52 / 3
                            font.family: "微软雅黑"
                        }
                        //职位
                        Text
                        {
                            id: positionText
                            anchors.left: callStateImage.right
                            anchors.leftMargin: 20 / 3
                            anchors.top: parent.top
                            anchors.topMargin: 100 / 3
                            text: position
                            color: "#b4b5b7"
                            font.pointSize: 40 / 3
                            font.family: "微软雅黑"
                        }

                        Image
                        {
                            id: moreImage
                            source: "./../images/callRecord/more.png"
                            width: 230 / 3
                            height: parent.height
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    mainstack.push("qrc:/qml/TeacherListInformation.qml",
                                                   {"teacher_name":contactName,
                                                       "teacher_position":position,
                                                       "teacher_ID":"1"
                                                   },true)
                                }

                                onPressed:
                                {
                                    moreImage.source = "./../images/callRecord/more-touch.png"
                                }
                                onReleased:
                                {
                                    moreImage.source = "./../images/callRecord/more.png"
                                }
                            }
                        }
                    }
                }
            }
        }

        ListView
        {
            id:listView
            width: parent.width -14
            anchors.left: parent.left
            anchors.leftMargin: 7
            anchors.top: editorItem.bottom
            anchors.topMargin: 30 / 3
            anchors.bottom: toolBar.top
            model:listModel
            delegate: delegate
            spacing: 20 / 3
            clip: true
        }

        //功能菜单栏
        MMenu {
            id: toolBar
            height:60
            width: parent.width
            bIsPerson: false
            bIsGroup: false
            bIsteacher: true
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            clip:true
        }
    }
}



