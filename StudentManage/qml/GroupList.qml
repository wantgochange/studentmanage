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
                id: edit
                source: "./../images/callRecord/editor.png"
                anchors.centerIn: parent
                width: 52
                height:52
                visible: mainstack.permissions
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("群组添加")
                        mainstack.push("qrc:/qml/GroupListInformation.qml")
                    }

                    onPressed:
                    {
                        edit.source = "./../images/callRecord/editor-click.png"
                    }
                    onReleased:
                    {
                        edit.source = "./../images/callRecord/editor.png"
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
    SearchLine{
        id: searchLine
        width: parent.width
        height: 42
        anchors.top: titlebarline.bottom
        clip:true
        z:1001
        onSignalgetinputtext: {
            namelistView.positionViewAtBeginning()
            searchText = text
        }
        onSignalgetfocus: {
            searchfocus = inputfocus
        }
    }
    MouseArea{
        z:100
        anchors.fill: parent
        visible: searchfocus
        onClicked: {
            grouproot.focus = true
            searchfocus = false
        }

    }

    Mline{
        id: searchline
        anchors.top: searchLine.bottom
        //        anchors.topMargin: 1
        width: parent.width
        color: "#2d2e17"
        height: 1
    }

    ListView{
        id: namelistView
        model:listModel
        delegate: delegate
        width: parent.width -14
        height: 300
        anchors.left: parent.left
        anchors.leftMargin: 7
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.top: searchline.bottom
        anchors.topMargin: 3
        anchors.bottom: toolBar.top
        spacing: 5
        clip: true
    }

    ListModel
    {
        id: listModel
        ListElement
        {
            activeState: "./../images/callRecord/answerPhone.png"
            contactName: "一班"
            position: "语文"
        }
        ListElement
        {
            activeState: "./../images/callRecord/havePhone.png"
            contactName: "二班"
            position: "数学"
        }
        ListElement
        {
            activeState: "./../images/callRecord/answerPhone.png"
            contactName: "三班"
            position: "英语"
        }
        ListElement
        {
            activeState: "./../images/callRecord/notCall.png"
            contactName: "四班"
            position: "体育"
        }
    }

    Item
    {
        id: listViewItem
        width: 1000 / 3
        height: 1389 / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
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
                        onClicked:{
                            mainstack.push("qrc:/qml/GroupListInformation.qml",
                                           {"groupname":contactName,
                                            "groupposition":position,
                                            "groupId":"1"
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

    //功能菜单栏
    MMenu {        
        id: toolBar
        height:60
        width: parent.width
        bIsPerson: false
        bIsGroup: true
        bIsteacher: false
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        clip:true
    }
}

