import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

Window {
    id:mainRoot
    width: 360
    height: 587
    visible: true
    StackView{
        id:mainstack
        initialItem: mainview
        anchors.centerIn: parent
        anchors.fill: parent
        property bool permissions
        SelectCLass{
            id:mainview
        }
    }
}
