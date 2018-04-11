import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
    id:groupEditroot
    width: 360
    height: 587
    property bool select_MoveState: false //是否为选择移动到某个组
    property int creatisGroup: 0   //创建的班组性质  0未知  1班 2组
    property string atid: ""


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
                        if(!select_MoveState){
                            mainstack.pop()
                            groupModel.cancel_openView()
                            groupModel.cancel_Selec_openView()
                        }
                        else{
                            select_MoveState = false
                            groupModel.cancel_openView()
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
        //删除按钮
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
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        groupModel.changeopenView("",true)
                        groupModel.cancel_Selec_openView()
                        mainstack.push("qrc:/qml/GroupDelete.qml")
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
//        anchors.topMargin: 1
        width: parent.width
        visible: true
        color: "#2d2e17"
        height: 1
    }


//    ListModel{
//        id:groupModel
//        ListElement{classname:"班";classnametxt:"一班";groupIdentity:1;groupnum:3;membername:"xiaoxiao"}
//        ListElement{classname:"组";classnametxt:"一组";groupIdentity:2;groupnum:2;membername:"dada"}
//        ListElement{classname:"班";classnametxt:"二班";groupIdentity:1;groupnum:4;membername:"三三"}
//        ListElement{classname:"组";classnametxt:"二组";groupIdentity:2;groupnum:1;membername:"四四"}
//    }

    ListView{
        id: namelistView
        model:groupModel
        delegate: grouplist
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.top: titlebarline.bottom
        anchors.topMargin: 3
        anchors.bottom: addormove.top
        spacing: 5
        clip: true
    }
    function classNameheight(atindex){
        if(atindex <0){
//            console.log(atindex,"97xxxxxxxxxxxxx错误");
            return 20;
        }

        if(atindex == 0){
//            console.log(atindex,"102xxxxxxxxxxxxx错误");
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
//            console.log(atindex,"116xxxxxxxxxxxxx错误");
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
            height:className.height==0 ? (openView ?( background.height +5 +55 * groupnum) : (background.height +5)):
                       (openView ?( background.height +25 +55 * groupnum) : (background.height +25))
//            height: openView ?( background.height +25 +50 * groupnum) : (background.height +25)
            property var iIndex: index//当前索引
            //类名
            Text {
                id: className
                height: classNameheight(index)
                text:compareGroup(index)  ? "班" : "组"
//                text: "班"
//                height: 15

                font.pixelSize: 15
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top:parent.top
                anchors.topMargin: 4
                color: "#fff"
                clip:true
                Component.onCompleted: {
//                    console.log(groupModel.m_listShowGroupforIndex(index),"群组性质====",className.height)
                }
            }

            //背景及内容
            Rectangle{
                id:background
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.top:className.bottom
                anchors.topMargin: 5//className.height==0 ? 20 :5
                height: 45
                radius: 4
                color: "#777857"
                width: parent.width - 20

                //群组成员移动区域
                MouseArea{
                    anchors.fill: parent
                    visible: select_MoveState
                    onClicked: {
                        console.log("跳转到",classNametxt.text)
                        if(groupModel.get_Select_openView() == 1){//只勾选一人
                            console.log("只有一个人",groupModel.get_SelectMember_ID())
                            getClass.visible = true
                            atid = id;
                        }
                        else{
                            console.log("多人拖拽")
                            groupModel.insert_AllMember(groupModel.get_SelectMember_ID(),id,2)
                            select_MoveState = false
                            groupModel.cancel_openView()
                            groupModel.cancel_Selec_openView()
                        }


                    }
                }

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

                //开关
                Image {
                    id: openclass
                    source: groupSelectAll ? "./../images/GroupEdit_image/all_open.png":"./../images/GroupEdit_image/all_off.png"
                    anchors.right: moreopen.left
                    anchors.top:parent.top
                    width: 110
                    height: 55
                    anchors.topMargin: -5
                    visible: !select_MoveState

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            groupModel.change_SelectAll_openView(id)
//                            if(!groupSelectAll){
////                                openclass.source = "./../images/GroupEdit_image/all_open.png"
////                                groupSelectAll = !groupSelectAll
//                                groupModel.change_SelectAll_openView(id)
//                            }
//                            else{
////                                openclass.source = "./../images/GroupEdit_image/all_off.png"
//                                groupModel.change_SelectAll_openView(id)
//                            }
                        }
                    }
                }

                //下拉
                Image {
                    id: moreopen
                    source: "./../images/GroupEdit_image/more_icon.png"
                    rotation: openView ? -90 :180
                    anchors.right: parent.right
                    anchors.top:parent.top
                    width: 50
                    height: 45
                    visible: !select_MoveState

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            groupModel.changeopenView(id,false)
//                            if(!openView){
//                                moreopen.rotation = -90
////                                openView = !openView
//                                groupModel.changeopenView(id)
//                            }
//                            else{
//                                moreopen.rotation = 180
////                                openView = !openView
//                                groupModel.changeopenView(id)
//                            }
                        }
                    }
                }
            }
            ListView{
                id:memberview
                model:groupnum
                delegate: groupmemberlist
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 3
                anchors.top: background.bottom
                anchors.topMargin: 3
                anchors.bottom: groupItem.bottom
                clip:true
                visible: !select_MoveState
            }
            Component{
                id:groupmemberlist
                Item{
                    width: 360
                    height: 50
                    Rectangle{
                        id:memberbackground
                        anchors.left: parent.left
                        anchors.leftMargin: 9
                        anchors.top:parent.top
                        anchors.topMargin: 2 //groupModel.getNameLetter(index-1) == nameLetter?5:10
                        height: 45
                        radius: 4
                        color: index == 0 ? "#ff8e3d" : "#606d7d"
                        width: parent.width - 20

                        //成员名
                        Text {
                            id: memberName
                            text: groupModel.getMemberName(groupItem.iIndex, index)
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
                            source: groupModel.get_SelectOne_openView(groupItem.iIndex,index) == 1 ? "./../images/GroupEdit_image/ON.png" : "./../images/GroupEdit_image/OFF.png"
                            anchors.right: parent.right
                            anchors.top:parent.top
                            width: 110
                            height: 55
                            anchors.topMargin: -5

                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    groupModel.change_SelectOne_openView(groupItem.iIndex,index)
                                }
                            }
                        }
                    }
                }
            }

        }
    }


    Connections{
        target:groupModel
        onUpdataToQml:
        {
            addormove.source = groupModel.get_Select_openView() != 0 ?"./../images/GroupEdit_image/move_icon.png":"./../images/GroupEdit_image/add_icon.png";
        }
    }
    //新增或移动
    Image {
        id: addormove
        source:groupModel.get_Select_openView()!= 0 ?"./../images/GroupEdit_image/move_icon.png":"./../images/GroupEdit_image/add_icon.png"
        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 5
        anchors.left: parent.left
        width: parent.width
        height: 50
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(groupModel.get_Select_openView()!= 0){//移动
                    select_MoveState = true
                    groupModel.changeopenView("",true) //关闭下拉状态
                }
                else{//新增
                    alertWindow.visible = true
                }
            }
            onPressed: {
                if(groupModel.get_Select_openView()!= 0)
                {
                    addormove.source = "./../images/GroupEdit_image/move_click.png"
                }
                else{
                    addormove.source = "./../images/GroupEdit_image/add_click.png"
                }
            }
            onReleased: {
                if(groupModel.get_Select_openView()!= 0)
                {
                    addormove.source = "./../images/GroupEdit_image/move_icon.png"
                }
                else{
                    addormove.source = "./../images/GroupEdit_image/add_icon.png"
                }
            }
        }
    }
    //新增窗口弹窗
    Item{
        id:alertWindow
        anchors.fill: parent
        visible: false
        MouseArea{
            anchors.fill: parent
            onClicked: {
                alertWindow.visible = false
            }
        }        
        AddWindow{
            alertTxt_top_text_set: "班"
            alertTxt_bottom_text_set:"组"
            anchors.centerIn: parent
            alertTxt_top_mouse.onClicked: {
                alertWindow.visible = false
                creatisGroup =1;
                addGroupWindow.visible = true
            }
            alertTxt_bottom_mouse.onClicked: {
                alertWindow.visible = false
                creatisGroup =2;
                addGroupWindow.visible = true
            }
        }
    }
    //输入新建班 或 组 名称
    Item{
        id:addGroupWindow
        anchors.fill: parent
        visible: false
        MouseArea{
            anchors.fill: parent
            onClicked: {
                addGroupWindow.visible = false
            }
        }
        Rectangle{
            anchors.fill: parent
            color: "#000"
            opacity: 0.3
        }
        Rectangle{
            id:addGroupWindow_rec
            radius: 3
            height: 228*2/3
            width: (23+618+35)/3
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 120
            border.color: "gray"
            border.width: 0.5
            color: "#fff"

            Item{
                id:title_item
                anchors.top:parent.top
                width: parent.width
                height: parent.height/3
                Text {
                    id: title_txt
                    text: "输入创建者名称"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 60/3
                }
            }
            Rectangle{
                id:input_item
                anchors.top:title_item.bottom
                width: parent.width -20
                anchors.left: parent.left
                anchors.leftMargin: 10
                height: parent.height/3
//                border.color: "gray"
                border.width: 0.5
                radius: 10
                TextInput{
                    id:input_txt
                    height: parent.height
                    width: parent.width - 20
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pixelSize: 50/3
                    font.family: "微软雅黑"
                    verticalAlignment: TextInput.AlignVCenter
                    horizontalAlignment: TextInput.AlignHCenter
                    clip: true
                    maximumLength: 5
                    color: "black"
                }
            }
            Item{
                id:btn_menu
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height/3
                Rectangle{
                    id:shure_rec
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    anchors.top:parent.top
                    anchors.topMargin: 5
                    height: parent.height -10
                    width: parent.width /2 -10
                    radius: 5

                    Text {
                        id: shure_btn
                        text: "确 定"
                        color: "black"
                        font.pixelSize: 45/3
                        anchors.centerIn: parent
                        verticalAlignment: TextInput.AlignVCenter
                        horizontalAlignment: TextInput.AlignLeft
                    }
                    Timer{
                        id:isEmpty
                        running: false
                        interval: 500
                        repeat: false
                        onTriggered: {
                            input_txt.text = ""
                            input_txt.color = "black"
                            input_txt.focus = true
                            shure_btn_mouse.visible = true
                        }
                    }

                    MouseArea{
                        id:shure_btn_mouse
                        anchors.fill: parent
                        onClicked: {
                            if(input_txt.text != "")
                            {
                                //群组模型增加
                                groupModel.add_Group(input_txt.text,creatisGroup)
                                addGroupWindow.visible = false
                                input_txt.text = ""
                                groupEditroot.focus = true                                

                            }
                            else{
                                input_txt.text = "不能为空"
                                input_txt.color = "red"
                                shure_btn_mouse.visible =false
                                isEmpty.running =true
                            }
                        }
                        onPressed: {
                            shure_rec.opacity = 0.5
                            shure_rec.color = "#238640"
                            shure_btn.color = "white"
                        }
                        onReleased: {
                            shure_rec.opacity = 1
                            shure_rec.color = "#fff"
                            shure_btn.color = "black"
                        }
                    }
                }
                Rectangle{
                    id:cancel_rec
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    anchors.top:parent.top
                    anchors.topMargin: 5
                    height: parent.height -10
                    width: parent.width /2 -10
                    radius: 5
                    Text {
                        id: cancel_btn
                        text: "取 消"
                        color: "black"
                        font.pixelSize: 45/3
                        anchors.centerIn: parent
                        verticalAlignment: TextInput.AlignVCenter
                        horizontalAlignment: TextInput.AlignLeft
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            input_txt.text = ""
                            addGroupWindow.visible = false
                            groupEditroot.focus = true
                        }
                        onPressed: {
                            cancel_rec.opacity = 0.5
                            cancel_rec.color = "#238640"
                            cancel_btn.color = "#fff"
                        }
                        onReleased: {
                            cancel_rec.opacity = 1
                            cancel_rec.color = "#fff"
                            cancel_btn.color = "black"
                        }
                    }
                }
            }
        }
    }
    //是否给予班长权限
    Item{
        id:getClass
        anchors.fill: parent
        visible: false
        MouseArea{
            anchors.fill: parent
            onClicked: {
                getClass.visible = false
                select_MoveState = false
            }
        }
        AddWindow{
            alertTxt_top_text_set: "指定为班长"
            alertTxt_bottom_text_set:"指定为班组成员"
            anchors.centerIn: parent
            alertTxt_top_mouse.onClicked: {
                console.log("指定为班长")
                getClass.visible = false
                groupModel.insert_AllMember(groupModel.get_SelectMember_ID(),atid,1)
                select_MoveState=false
                groupModel.cancel_openView()
                groupModel.cancel_Selec_openView()
            }
            alertTxt_bottom_mouse.onClicked: {
                console.log("指定为班组成员")
                getClass.visible = false
                groupModel.insert_AllMember(groupModel.get_SelectMember_ID(),atid,2)
                select_MoveState=false
                groupModel.cancel_openView()
                groupModel.cancel_Selec_openView()
            }
        }
    }
}
