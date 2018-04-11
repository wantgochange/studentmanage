import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Item {
    visible: true
    width: 360
    height: 587

    property string contact_name: ""
    property string contact_position: ""
    property string contact_ID: ""

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

        Image {
            id: edit
            source: "./../images/callRecord/editor.png"
            visible: mainstack.permissions
            anchors.right: parent.right
            anchors.rightMargin: 10 / 3
            anchors.top: parent.top
            anchors.topMargin: 10 / 3
            width: 52
            height:52
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("信息修改")
                    mainstack.push("qrc:/qml/AddPersonPage.qml",{"contact_name":contact_name,
                                       "contact_position":contact_position,
                                       "contact_ID":contact_ID
                                   },true)
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
//        height: 1260 / 3
        anchors.top:headerImage.bottom
        anchors.bottom: parent.bottom
        z: 99

        source: "./../images/contact/bottom_bg_02.png"

        //联系人姓名
        Text
        {
            id: contactsName
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 12 / 3
            text: contact_name
            color: "#ffffff"
            font.pointSize: 60 / 3
            font.family: "微软雅黑"
        }


        //职位
        Text
        {
            id: position
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: contactsName.bottom
            anchors.topMargin: 23 / 3
            text:contact_position + " " +contact_ID
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
//            text: "222"
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
            text: qsTr("个人信息")
            color: "#ffffff"
            font.pointSize: 54 / 3
            font.family: "微软雅黑"
        }
        //班级信息
        Text
        {
            id: longitude
            anchors.right: parent.right
            anchors.rightMargin: 30 / 3
            anchors.top: position.bottom
            anchors.topMargin: 30 / 3
            text: groupModel.getGroupName(personModel.getAtgroupInfo(contact_ID))
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
                    //及格状态
                    Image
                    {
                        id: connectState
                        width: 51  / 3
                        height: 113  / 3
                        anchors.top: parent.top
                        anchors.topMargin: 33 / 3
                        anchors.left: parent.left
                        anchors.leftMargin: 40 / 3
                        source: comperData(personModel.getData(contact_ID,index),index)
                    }
                    //科目
                    Text
                    {
                        id: netWork
                        anchors.top: parent.top
                        anchors.topMargin: 33 / 3
                        anchors.left: connectState.right
                        anchors.leftMargin: 18 / 3
                        text: subject_txt(index)
                        color: "#ffffff"
                        font.pointSize: 52 / 3
                        font.family: "微软雅黑"
                    }
                    //分数
                    Text {
                        id: score_txt
                        text: dataDeal(personModel.getData(contact_ID,index),contact_ID,index)
                        anchors.top: parent.top
                        anchors.topMargin: 33 / 3
                        anchors.right: parent.right
                        anchors.rightMargin: 38 / 3
                        color: "#ffffff"
                        font.pointSize: 52 / 3
                        font.family: "微软雅黑"
                    }
                }
            }
        }
        //视图
        ListView
        {
            id: listView
            width: parent.width;
//            height: 266
            anchors.top: stateInformation.bottom
            anchors.topMargin: 30 / 3
            anchors.bottom: parent.bottom
            model:10  //关联数据模型
            delegate:delegate  //关联代理
            spacing: 20 / 3
            clip:true
        }
    }

    //科目返回
    function subject_txt(atindex){
        switch(atindex){
        case 0:
            return "语文";
        case 1:
            return "数学";
        case 2:
            return "英语";
        case 3:
            return "体育";
        case 4:
            return "班主任";
        case 5:
            return "身高";
        case 6:
            return "体重";
        case 7:
            return "缺课记录";
        case 8:
            return "记过次数";
        case 9:
            return "职位";

        }
    }
    //及格线比较
    function comperData(score,atindex){
        if(atindex >=4){
            return "";
        }
        else{
            if(score >90 && score<=100){
                return "./../images/contact/connection_successful.png";
            }
            else if(score>60 && score< 90){
                return "./../images/contact/connection_fail.png";
            }
            else if(score < 60 && score >=0){
                return "./../images/contact/not-connected.png";
            }
        }



    }
    //职位 班主任 返回
    function dataDeal(r_data,contact_ID,index){
        if(index == 4){
            return personModel.getTeacher(contact_ID)
        }
        else if(index == 9){
            return personModel.getPosition(contact_ID)
        }
        else{
            return r_data;
        }
    }
}
