import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Item {
    visible: true
    width: 360
    height: 587

    property string teacher_name: ""
    property string teacher_position: ""
    property string teacher_ID: ""

    //头部背景图片
    Image
    {
        id: headerImage
        width: parent.width
        height: 460 / 3
        anchors.top: parent.top
        source: "./../images/contact/top_bg_01.png"
        //返回
        Image
        {
            id: returnImage
            width: 156 / 3
            height: 156 / 3
            anchors.left: parent.left
            anchors.leftMargin: 10 / 3
            anchors.top: parent.top
            anchors.topMargin: 10 / 3
            source: "./../images/contact/return.png"
            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    mainstack.pop()
                }

                onPressed:
                {
                    parent.source = "./../images/contact/return-click.png"
                }
                onReleased:
                {
                    parent.source = "./../images/contact/return.png"
                }
            }
        }

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
                    mainstack.push("qrc:/qml/AddTeacherPage.qml",{"teacher_name":teacher_name,
                                       "teacher_position":teacher_position,
                                       "teacher_ID":teacher_ID
                                   },true)
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

        //照片头像
        Image
        {
            id: photo
            width: 235 / 3
            height: 235 / 3
            anchors.top: parent.top
            anchors.topMargin: 220 / 3
            z: 999
            //水平居中
            anchors.horizontalCenter: parent.horizontalCenter
            source: "./../images/contact/Head-portrait.png"
        }
    }

    //底部背景图片
    Image
    {
        id: bottomImage
        width: parent.width
        height: 1460 / 3
        z: 99
        anchors.top: headerImage.bottom
        source: "./../images/contact/bottom_bg_02.png"

        //联系人姓名
        Text
        {
            id: contactsName
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 12 / 3
            text: teacher_name
            color: "#ffffff"
            font.pointSize: 60 / 3
            font.family: "微软雅黑"
        }


        //职位
        Text
        {
            id: position
//            anchors.right: contactsName.left
//            anchors.rightMargin: -40 / 3
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: contactsName.bottom
            anchors.topMargin: 23 / 3
            text:teacher_position + " " +teacher_ID
            color: "#bdbed7"
            font.pointSize: 45 / 3
            font.family: "微软雅黑"
        }

//        //编号
//        Text
//        {
//            id: positionNum
//            anchors.left: contactsName.right
//            anchors.leftMargin: -40 / 3
//            anchors.top: contactsName.bottom
//            anchors.topMargin: 30 / 3
//            text: teacher_ID
//            color: "#bdbed7"
//            font.pointSize: 45 / 3
//            font.family: "微软雅黑"
//        }

        //个人信息
        Text
        {
            id: stateInformation
            anchors.left: parent.left
            anchors.leftMargin: 40 / 3
            anchors.top: position.bottom
            anchors.topMargin: 30 / 3
            text: qsTr("教授班级")
            color: "#ffffff"
            font.pointSize: 54 / 3
            font.family: "微软雅黑"
        }
        //教师信息
        Text
        {
            id: longitude
            anchors.right: parent.right
            anchors.rightMargin: 30 / 3
            anchors.top: position.bottom
            anchors.topMargin: 30 / 3
            text: teacher_position
            color: "#b4b5b7"
            font.pointSize: 45 / 3
            font.family: "微软雅黑"
        }

        //代理
        Component
        {
            id: delegate
            Item
            {
                id: wrapper;
                width: parent.width;
                height: 179  / 3
                Rectangle
                {
                    width: 1040 / 3
                    height: 179 / 3
                    color: "#777857"
                    radius: 10
                    anchors.horizontalCenter: parent.horizontalCenter

                    //教授科目
                    Text
                    {
                        id: netWork
                        anchors.top: parent.top
                        anchors.topMargin: 33 / 3
                        anchors.left: parent.left
                        anchors.leftMargin: 40 / 3
                        text: teacherModel.get_TeacherGroup(index,teacherModel.getTeacherGroup(teacher_ID))
                        color: "#ffffff"
                        font.pointSize: 52 / 3
                        font.family: "微软雅黑"
                    }
//                    //管辖班级
//                    Text {
//                        id: score_txt
//                        text: "一年级"
//                        anchors.top: parent.top
//                        anchors.topMargin: 33 / 3
//                        anchors.right: parent.right
//                        anchors.rightMargin: 38 / 3
//                        color: "#ffffff"
//                        font.pointSize: 52 / 3
//                        font.family: "微软雅黑"
//                    }
                }
            }
        }
        //视图
        ListView
        {
            id: listView
            width: parent.width;
            anchors.top: stateInformation.bottom
            anchors.topMargin: 30 / 3
            anchors.bottom: parent.bottom
            model:teacherModel.getTeacherGroupcount(teacher_ID)  //关联数据模型
            delegate:delegate  //关联代理
            spacing: 20 / 3
            clip:true
        }
    }
}
