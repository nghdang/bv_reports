import QtQuick 2.0
import QtQuick.Controls 2.0

Button {
    id: root

    property alias buttonIcon: rootIcon.source
    property alias dropIcon: rootDropIcon.source

    hoverEnabled: true
    checkable: true

    contentItem: Item {
        id: rootContent

        Image {
            id: rootIcon
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            scale: Image.PreserveAspectFit
        }

        Label {
            id: rootLabel
            anchors.left: rootIcon.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pixelSize: 28
            color: "grey"
            text: root.text
        }

        Image {
            id: rootDropIcon
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    background: Rectangle {
        radius: 10
        color: root.pressed ? "#222" : root.hovered ? "#444" : "#333"
    }
}
