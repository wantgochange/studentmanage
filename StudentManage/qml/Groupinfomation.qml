import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
    id:group_informationroot
    width: 360
    height: 587
    property var groupID
    property bool isDelete: false
    property int temp

    //背景
    Image {
        id: backImg
        anchors.fill: parent
        source: "./../images/callRecord/bottom_bg_02.png"
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
        Text {
            id: groupName
            text: groupModel.getGroupName(groupID)
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 20
            color: "white"
        }
        Item{
            width: 52
            height:52
            anchors{
                left:titleBar.left
                top:titleBar.top
                leftMargin: 3
                topMargin: 3
            }
            Image {
                id: goback
                source: "./../images/IMSetting_image/back_icon.png"
                anchors.centerIn: parent
                width: 52
                height:52
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(isDelete){
                            isDelete = false
                            groupModel.cancel_Selec_openView()
                        }
                        else{
                            mainstack.pop()
                            groupModel.cancel_Selec_openView()
                        }
                    }
                    onPressed: {
                        goback.source = "./../images/IMSetting_image/back_click.png"
                    }
                    onReleased: {
                        goback.source = "./../images/IMSetting_image/back_icon.png"
                    }
                }
            }
        }

        //删除群组成员
        Item{
            width: 52
            height:52
            anchors{
                right:titleBar.right
                top:titleBar.top
                rightMargin: 3
                topMargin: 3
            }
            Image {
                id: delete_group
                source: "./../images/GroupEdit_image/deletebtn_icon.png"
                anchors.centerIn: parent
                width: 52
                height:52
                visible: !isDelete
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        isDelete = true
                    }
                    onPressed: {
                        delete_group.source = "./../images/GroupEdit_image/deletebtn_click.png"
                    }
                    onReleased: {
                        delete_group.source = "./../images/GroupEdit_image/deletebtn_icon.png"
                    }
                }
            }
        }

    }

    Mline{
        id: titlebarline
        anchors.top: titleBar.bottom
        width: parent.width
        visible: true
        color: "#2d2e17"
        height: 1
    }

//    Connections{
//        target:phonebook
//        onPhonebook_updataToQml:
//        {
////            namelistView.model = groupModel.getMemberNum(groupID)
////            namelistView.model = groupModel.getMemberNum(groupID)
////            for(temp =0;temp<groupModel.getMemberNum(groupID);temp++){
////                memberopenclass.source =
////                        groupModel.get_SelectOne_openView(groupModel.getGroupIndex(groupID),temp) == 1
////                        ? "./../images/GroupEdit_image/ON.png" : "./../images/GroupEdit_image/OFF.png"
////            }
//        }
//    }


    ListView{
        id: namelistView
        model:groupModel.getMemberNum(groupID)
        delegate: grouplist
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.top: titlebarline.bottom
        anchors.topMargin: 3
        anchors.bottom: parent.bottom
        spacing: 5
        clip: true
    }
    Component{
        id:grouplist
        Item{
            id:groupMemberItem
            width: 360
            height: background.height +5
            Rectangle{
                id:background
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.top:parent.top
                anchors.topMargin: 5
                height: 45
                radius: 4
                color: "#777857"
                width: parent.width - 20
                //成员名
                Text {
                    id: memberNametxt
                    text: groupModel.getMemberName(groupModel.getGroupIndex(groupID),index)
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pixelSize: 20
                    anchors.top:parent.top
                    anchors.topMargin: 10
                    color: "#fff"
                }
                //开关
                Image {
                    id: memberopenclass
                    source: groupModel.get_SelectOne_openView(groupModel.getGroupIndex(groupID),index) == 1 ? "./../images/GroupEdit_image/ON.png" : "./../images/GroupEdit_image/OFF.png"
                    anchors.right: parent.right
                    anchors.top:parent.top
                    width: 110
                    height: 55
                    anchors.topMargin: -5
                    visible: isDelete
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            groupModel.change_SelectOne_openView(groupModel.getGroupIndex(groupID),index)
                            refreshModel.running = true
                        }
                    }
                }
            }
        }
    }
    Timer{
        id:refreshModel
        running: false
        repeat: false;
        interval: 100
        onTriggered: {
            namelistView.model = 0
            namelistView.model = groupModel.getMemberNum(groupID)
        }
    }

    //新增和删除
    Image {
        id: delete_img
        source:!isDelete ? "./../images/GroupEdit_image/add_icon.png" :"./../images/GroupEdit_image/delete_icon.png"
//        source: !isDelete ? "" :"./../images/GroupEdit_image/delete_icon.png"
        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 5
        anchors.left: parent.left
        width: parent.width
        height: 50
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(isDelete){
                    groupModel.delete_Member(groupID)
                    isDelete = false
                    refreshModel.running = true
                }
                else{
                    console.log("新增群组成员")
                    mainstack.push("qrc:/qml/GroupAddMember.qml",{"groupId":groupID},true)
                }
            }
            onPressed: {
                if(isDelete){
                    delete_img.source = "./../images/GroupEdit_image/delete_click.png"
                }
                else{
                    delete_img.source = "./../images/GroupEdit_image/add_click.png"
                }
            }
            onReleased: {
                if(isDelete){
                    delete_img.source = "./../images/GroupEdit_image/delete_icon.png"
                }
                else{
                    delete_img.source = "./../images/GroupEdit_image/add_icon.png"
                }
            }
        }
    }
}

