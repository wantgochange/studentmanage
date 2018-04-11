import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
    id:groupDeleteroot
    width: 360
    height: 587

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
                        mainstack.pop()
                        groupModel.cancel_Selec_openView()
                        groupModel.cancel_openView()
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
    }
    Mline{
        id: titlebarline
        anchors.top: titleBar.bottom
        width: parent.width
        visible: true
        color: "#2d2e17"
        height: 1
    }

    ListView{
        id: namelistView
        model:groupModel
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
                    anchors.right: parent.right
                    anchors.top:parent.top
                    width: 110
                    height: 55
                    anchors.topMargin: -5

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            groupModel.change_SelectAll_openView(id)
                        }
                    }
                }
            }
        }
    }

    //删除
    Image {
        id: delete_img
        source:"./../images/GroupEdit_image/delete_icon.png"
        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 5
        anchors.left: parent.left
        width: parent.width
        height: 50
        MouseArea{
            anchors.fill: parent
            onClicked: {
                groupModel.delete_Group()
                mainstack.pop()
            }
            onPressed: {
                delete_img.source = "./../images/GroupEdit_image/delete_click.png"
            }
            onReleased: {
                delete_img.source = "./../images/GroupEdit_image/delete_icon.png"
            }
        }
    }
}
