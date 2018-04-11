import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
    id:grouproot
    width: 360
    height: 587

    property string searchText: ""
    property bool searchfocus: false
    //背景
    Image {
        id: backImg
        anchors.fill: parent
        source: "./../images/person_image/bottom_bg_02.png"
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
        Item {
            id: introduction
            width: 100
            height:50
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: introduction_txt
                text: "班 级"
                color: "#fff"
                font.pixelSize: 25
                anchors.centerIn: parent
            }
        }
        Item{
                width: 52
                height:52
                visible:  mainstack.permissions
                anchors{
                    right:titleBar.right
                    top:titleBar.top
                    rightMargin: 3
                    topMargin: 3
                }
                Image {
                    id: edit

                    source: "./../images/GroupList_image/eidt_icon.png"
                    anchors.centerIn: parent
                    width: 52
                    height:52
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            mainstack.push("qrc:/qml/GroupEdit.qml")
                        }

                        onPressed: {
                            edit.source = "./../images/GroupList_image/edit_click.png"
                        }
                        onReleased: {
                            edit.source = "./../images/GroupList_image/eidt_icon.png"
                        }
                    }
                }
            }

    }

    ListView{
        id: namelistView
        model:groupModel
        delegate: grouplist
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.top: titleBar.bottom
        anchors.topMargin: 3
        anchors.bottom: parent.bottom
        spacing: 5
        clip: true
    }
    function classNameheight(atindex){
        if(atindex <0){
//            console.log(atindex,"list 121xxxxxxxxxxxxx错误");
            return 20;
        }

        if(atindex == 0){
//            console.log(atindex,"list 125xxxxxxxxxxxxx错误");
            return 20;
        }
        else{
            if(groupModel.m_listShowGroupforIndex(atindex-1) == groupModel.m_listShowGroupforIndex(atindex)){
                return 0;
            }
            else{
                return 20
            }
        }
//        return 20
    }
    function compareGroup(atindex){
        if(atindex<0){
//            console.log(atindex,"list 141xxxxxxxxxxxxx错误");
            return false;
        }

        if(groupModel.m_listShowGroupforIndex(atindex) == 1){
            return true;
        }
        else{
            return false;
        }

    }
    Component{
        id:grouplist

        Item {
            id: groupItem
            width: 360
            height:className.height==0 ?(background.height +5):(background.height +25)
            property var iIndex: index//当前索引
            //类名
            Text {
                id: className
                text: compareGroup(index) ? "文科班" : "理科班"
//                text:"班"
                height: classNameheight(index)
                font.pixelSize: 15
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top:parent.top
                anchors.topMargin: 4
                color: "#fff"
                clip:true
                Component.onCompleted: {
                }
            }


            Rectangle{
                id:background
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.top:className.bottom
                anchors.topMargin: 5
                height: 45
                radius: 4
                color: "#777857"
                width: parent.width - 20

                //班组名
                Text {
                    id: classNametxt
                    text: name
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pixelSize: 20
                    anchors.top:parent.top
                    anchors.topMargin: 10
                    color: "#fff"
                }
                //成员数目
                Image {
                    id: membernum
                    source: "./../images/GroupList_image/memberNum_icon.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: 30
                    height: 25
                }
                Text {
                    id: membernumtxt
                    text: groupnum
                    anchors.left: membernum.right
                    anchors.leftMargin: 10
                    anchors.top:parent.top
                    anchors.topMargin: 13
                    font.pixelSize: 15
                    color: "#fff"
                }
                MouseArea{
                    id:goGroupIm
                    anchors.fill: parent
                    onClicked: {
                         mainstack.push("qrc:/qml/ImMessPage.qml",{"pIMId":id,
                                            "pIMname":name,"isGroup":true},true)
                    }
                }

                //群组详情界面
                Image {
                    id: moreopen
                    source: "./../images/GroupEdit_image/more_icon.png"
                    anchors.right: parent.right
                    rotation: 180
                    anchors.top:parent.top
                    width: 50
                    height: 45
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            mainstack.push("qrc:/qml/Groupinfomation.qml",{"groupID":id},true)
                        }
                        onPressed: {
                            moreopen.source = "./../images/GroupEdit_image/more_click.png"
                        }
                        onReleased: {
                            moreopen.source = "./../images/GroupEdit_image/more_icon.png"
                        }
                    }
                }
            }
        }
    }
    //功能菜单栏
    MMenu {
        id: toolBar
        height:60
        width: parent.width

        bIsPerson: false
        bIsGroup: true
        bIsteacher:  false
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        clip:true
    }
}

