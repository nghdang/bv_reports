import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: root

    Label {
        id: welcomeLabel
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: 36
        color: "lightgrey"
        text: "This is FirstUse"
    }
}
