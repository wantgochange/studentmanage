import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Item {
    id:personroot
    width: 360
    height: 587
    property var posindex
    //搜索框内容
    property string searchText: ""
    property bool searchfocus: false


    //背景
    Image {
        id: backImg
        anchors.fill: parent
        source: "./../images/person_image/bottom_bg_02.png"
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
                text: "学 生"
                color: "#fff"
                font.pixelSize: 25
                anchors.centerIn: parent
            }
        }
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
                        console.log("人员添加")
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
//        anchors.topMargin: 1
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
            personModel.setFilter(searchText)
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
            personroot.focus = true
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
//    ListModel{
//        id:personModel
//        ListElement{nameLetter:"A";name:"Ala";position:"班长";
//            personheight:171;personweight:100;person_yuwen:99;person_math:100;person_english:100;person_tiyu:88;}
//        ListElement{nameLetter:"B";name:"Bla";position:"无";
//        personheight:171;personweight:100;person_yuwen:99;person_math:100;person_english:100;person_tiyu:88;}
//        ListElement{nameLetter:"C";name:"Cla";position:"无";
//        personheight:171;personweight:100;person_yuwen:99;person_math:100;person_english:100;person_tiyu:88;}
//        ListElement{nameLetter:"D";name:"Dla";position:"无";
//        personheight:171;personweight:100;person_yuwen:99;person_math:100;person_english:100;person_tiyu:88;}
//    }

    //联系人列表
    ListView {
        id: namelistView
//        model:mpersonModel
        model:personModel
        delegate: personlist
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 6
        anchors.top: searchline.bottom
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
                height: personModel.getNameLetter(index-1) == nameLetter?0:13
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
                id:leftposition
                anchors.left: leftText.left
                anchors.top: leftText.bottom
                anchors.topMargin: 1
                font.pixelSize:	13
                color: "#b6b6b6"
                text: position
            }
            MouseArea {
                id: viewmouse
                width:parent.width
                anchors.top:headpic.top
                anchors.bottom: headpic.bottom
                onClicked: {
                    mainstack.push("qrc:/qml/PersonInformation.qml",{"contact_name":leftText.text,
                                       "contact_position":leftposition.text,
                                       "contact_ID":id
                                   },true)
                }
            }       
        }
    }
    //右滚动轴
    ListView{
        id:rightScrollerlistview
        model:rightScrollermodel
        ListModel{
            id:rightScrollermodel
            ListElement {num:"#"}
            ListElement {num:"A"}
            ListElement {num:"B"}
            ListElement {num:"C"}
            ListElement {num:"D"}
            ListElement {num:"E"}
            ListElement {num:"F"}
            ListElement {num:"G"}
            ListElement {num:"H"}
            ListElement {num:"I"}
            ListElement {num:"J"}
            ListElement {num:"K"}
            ListElement {num:"L"}
            ListElement {num:"M"}
            ListElement {num:"N"}
            ListElement {num:"O"}
            ListElement {num:"P"}
            ListElement {num:"Q"}
            ListElement {num:"R"}
            ListElement {num:"S"}
            ListElement {num:"T"}
            ListElement {num:"U"}
            ListElement {num:"V"}
            ListElement {num:"W"}
            ListElement {num:"X"}
            ListElement {num:"Y"}
            ListElement {num:"Z"}
        }
        delegate:rightlist
        anchors.right: parent.right
        anchors.top:searchline.bottom
        anchors.topMargin: 3
        anchors.rightMargin: 4
        width: 10
        anchors.bottom: parent.bottom

        clip:true
        interactive:false
        spacing: 4

        MouseArea{
            id:container
            width:rightScrollerlistview.width
            height:rightScrollerlistview.height
            preventStealing:true//必须设置的属性，否则Flickable会独占鼠标事件。
            anchors.fill: parent
            hoverEnabled: true
            onPressed: adjustPos(container.mouseX,container.mouseY);
            onPositionChanged: adjustPos(container.mouseX,container.mouseY);
            onReleased: {
                hinttime.running=true
                if(centertxt.text=="#")
                {
                    searchText=""
                    personModel.setFilter(searchText)
                }
                else
                {
                    searchText=centertxt.text
                    personModel.setFilter(searchText)
                }
            }
        }
    }
    Component{
        id:rightlist
        Item{
            width: 11
            height:11
            Text {
                id: rightScrollerText
                anchors.fill: parent
                color: "white"
                anchors.centerIn: parent
                font.pixelSize:	11
                text:num
            }
        }
    }

    //功能菜单栏
    MMenu {
        id: toolBar
        height:60
        width: parent.width

        bIsPerson: true
        bIsGroup: false
        bIsteacher:  false
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        clip:true
    }


    //获取索引值
    function adjustPos(x,y) {
        posindex = rightScrollerlistview.indexAt(x,y);
//        console.log("字母查询：ddddddd ",posindex)
        if(posindex < 0)
        {
            return;
        }
        else
        {
            centertxt.text=rightScrollermodel.get(posindex).num
        }
    }
    Text{
        id:centertxt
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: 35
    }

    //清除搜索框内容
    function clearSearchText()
    {
        searchLine.inputtext.text = ""
        searchText=centertxt.text
        personModel.setFilter(searchText)
    }
    //提示时间
    Timer{
        id:hinttime
        interval: 1000
        running: false
        repeat:false
        onTriggered: {
            centertxt.text=""
        }
    }
}



