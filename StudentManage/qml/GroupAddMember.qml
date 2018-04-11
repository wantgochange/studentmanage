import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Item {
    id:addCallroot
    width: 360
    height: 587
    property string groupId   //群id
//    property string myId : "000"
    //背景
    Image {
        id: backImg
        anchors.fill: parent
        source: "./../images/callRecord/bottom_bg_02.png"
//            fillMode:Image.TileHorizontally
    }
    Image {
        id: midback
        source: "./../images/person_image/bg.png"
        width: parent.width
        height: titleBar.height
        fillMode: Image.Tile
    }


    //标题栏
    Item{
        id:titleBar
        width: parent.width
        height: 59

        Item{
            width: 52
            height:52
            anchors{
                left:titleBar.left
                top:titleBar.top
                leftMargin: 3
                topMargin: 3
            }
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
        }
    }

    //联系人列表
    ListView {
        id: namelistView
        model:personModel
        delegate: personlist
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 6
        anchors.top: titleBar.bottom
        anchors.topMargin: 3
        anchors.bottom: parent.bottom
        clip: true
    }

    Component{
        id:personlist
        Item{
            id:peritem
            height:headpic.height + firstName.height == 0 ?0: 65
            width: 360
            //首字母查询
            Text {
                id: firstName
                height: mpersonModel.getNameLetter(index-1) == nameLetter?0:13
                color: "white"
                clip: true
                anchors.top:parent.top
                font.pixelSize:	13
                anchors.left: parent.left
                anchors.leftMargin: 13
                text: nameLetter
            }
            //头像
            Image{
                id:headpic
                anchors.left: parent.left
                anchors.leftMargin: 11
                anchors.top:firstName.bottom
                anchors.topMargin: firstName.height == 0?20: 7
                source: "./../images/person_image/headpic_icon.png"
                width: 40
                height: 40
            }

            //联系人名字
            Text {
                id: leftText
                color: "white"
                anchors.left: headpic.right
                anchors.leftMargin: 9
                anchors.top: headpic.top
                font.pixelSize:	18
                text: name
            }
            //联系人职务
            Text {
                anchors.left: leftText.left
                anchors.top: leftText.bottom
                anchors.topMargin: 1
                font.pixelSize:	13
                color: "#b6b6b6"
                text: position
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("添加群组成员")
                    if(groupModel.comper_groupMember(groupId,id)){
                        alert_window_item.visible = true
                        alert_window.content_text_set = "重复添加"
                    }
                    else{
                        groupModel.append_groupMember(groupId,id)
                        mainstack.push("qrc:/qml/GroupList.qml",{"groupID":groupId},true)
                    }
                }
            }
        }
    }
    //警告提示
    Item{
        id:alert_window_item
        anchors.fill: parent
        visible: false
        z :100
        MouseArea{
            anchors.fill: parent
            onClicked: {
                alert_window_item.visible = false
                alert_window.content_text_set = ""
            }
        }
        Timer{
            running: alert_window_item.visible
            interval: 500
            onTriggered: {
                alert_window_item.visible = false
                alert_window.content_text_set = ""
            }
        }
        AlertWindow{
            id:alert_window
            anchors.centerIn: parent
            content_text_set:""
        }
    }

}



