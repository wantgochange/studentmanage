import QtQuick 2.0

Item {
    width: 360
    height: 587


    property string contact_name: ""
    property string contact_position: ""
    property string contact_ID: ""

    property string input_name: ""
    property string input_height: ""
    property string input_width: ""
    property string input_yuwen: ""
    property string input_math: ""
    property string input_english: ""
    property string input_tiyu: ""
    property string input_teacher: ""
    property string input_runclass: ""
    property string input_beddata: ""
    property string input_position: ""


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

        //照片头像
        Image
        {
            id: photo
            width: 235 / 3
            height: 235 / 3
            anchors.top: parent.top
            anchors.topMargin: 220 / 3
            z: 999
            anchors.horizontalCenter: parent.horizontalCenter
            source: "./../images/contact/Head-portrait.png"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {

//                }
//                onPressed: {
//                    photo.source = "./../images/AddPerson/click_add_picture.png"
//                }
//                onReleased: {
//                    photo.source = "./../images/AddPerson/icon_add_picture.png"
//                }
//            }
        }
    }

    //底部背景图片
    Image
    {
        id: bottomImage
        width: parent.width
        height: 1460 / 3
        anchors.top: headerImage.bottom
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
            text:contact_position
            color: "#bdbed7"
            font.pointSize: 45 / 3
            font.family: "微软雅黑"
        }
    }


    ListView
    {
        id: listView
        width: parent.width
        anchors.top: bottomImage.top
        anchors.topMargin: 220 / 3
        anchors.bottom: push_ok.top
        model:listModel
        delegate:delegate
        spacing: 20 / 3
        clip:true
    }
    ListModel{
        id:listModel
        ListElement{
            imageSource:"./../images/AddPerson/icon_head.png"
            txtName:"姓名 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"职位 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_head.png"
            txtName:"语文 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_position.png"
            txtName:"数学 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_Id.png"
            txtName:"英语 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"体育 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"班主任 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"身高 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"体重 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"缺课记录 :"
            input_txt:""
        }
        ListElement{
            imageSource:"./../images/AddPerson/icon_netNum.png"
            txtName:"记过次数 :"
            input_txt:""
        }

    }
    Component{
        id:delegate
        Item
        {
            width: parent.width
            height: 179  / 3

            Rectangle
            {
                width: 1040 / 3
                height: 179 / 3
                color: "#777857"
                radius: 10
                anchors.horizontalCenter: parent.horizontalCenter
                //头像
                Image
                {
                    id: connectState
                    width: 58  / 3
                    height: 57  / 3
                    anchors.left: parent.left
                    anchors.leftMargin: 20 / 3
                    anchors.verticalCenter: parent.verticalCenter
                    source: imageSource
                }
                //类别
                Text {
                    id: contentName
                    anchors.left: connectState.right
                    anchors.leftMargin: 30 / 3
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#c3c3b8"
                    font.pointSize: 45 / 3
                    font.family: "微软雅黑"
                    text: txtName
                }

                //姓名 输入框
                Item{
                    id:text_input_item
                    width: parent.width - contentName.width - connectState.width - 40
                    height: parent.height
                    anchors.left: contentName.right
                    anchors.leftMargin: 5
                    anchors.verticalCenter: parent.verticalCenter

                    TextInput{
                        id:text_input
                        font.pixelSize: 52/3
                        color: "#fff"
                        font.family: "微软雅黑"
                        verticalAlignment: TextInput.AlignVCenter
                        horizontalAlignment: TextInput.AlignLeft
                        anchors.fill: parent
                        property int maxLength: 3//最大输入长度
                        onLengthChanged:
                        {
                            get_input_txt(index,text_input.text)
                            if(text_input.length > maxLength)
                            {
                                alert_window_item.visible = true
                                alert_window.content_text_set = "超出输入范围"
                                var prePosition = cursorPosition;
                                text_input.text = text_input.text.substring(0, maxLength);
                                cursorPosition = Math.min(prePosition, maxLength);
                            }
                        }

                        onFocusChanged :{
                            if(text_input.focus){
                                text_input.color = "#1df65c"
                            }
                            else{
                                text_input.color = "#fff"
                            }
                        }
                    }
                }
            }
        }
    }
    function get_input_txt(at_index,input_text){
        console.log(at_index,input_text,"输入框内容")
        switch(at_index){
        case 0:
            input_name = input_text;
            break;
        case 1:
            input_position = input_text;
            break;
        case 2:
            input_yuwen = input_text;
            break;
        case 3:
            input_math = input_text;
            break;
        case 4:
            input_english = input_text;
            break;
        case 5:
            input_tiyu = input_text;
            break;
        case 6:
            input_teacher = input_text;
            break;
        case 7:
            input_height = input_text;
            break;
        case 8:
            input_width = input_text;
            break;
        case 9:
            input_runclass = input_text;
            break;
        case 10:
            input_beddata = input_text;
            break;

        }
    }
    function no_kong(){
        if(input_name == "" ||input_position == "" ||input_yuwen == ""
                ||input_math == "" ||input_tiyu == "" ||input_teacher == "" ||input_runclass == "" ||input_width == ""
                ||input_height==""  || input_beddata==""){
            alert_window_item.visible = true
            alert_window.content_text_set = "不能存在空值"
            return false;
        }
        return true
    }

    //确认按钮
    Image{
        id:push_ok
        source: "./../images/AddPerson/icon_push.png"
        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 5
        height: 150 /3
        width: parent.width
        anchors.left: parent.left
        MouseArea{
            anchors.fill: parent
            onClicked: {
                //判断是否有空值
                if(no_kong()){
                    personModel.changePersonInfo(contact_ID,input_name,input_position,
                                                 input_yuwen,input_math,input_english,
                                                 input_tiyu,input_teacher,input_height,
                                                 input_width,input_runclass,input_beddata)
                    mainstack.push("qrc:/qml/PersonList.qml")
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
