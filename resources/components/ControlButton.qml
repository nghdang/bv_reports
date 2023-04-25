import QtQuick 2.0
import QtQuick.Controls 2.0

Button {
    id: root

    hoverEnabled: true

    contentItem: Text {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        text: root.text
        font.bold: true
        font.pixelSize: 22
        color: "white"
    }

    background: Rectangle {
        border.color: "transparent"
        border.width: 2
        color: root.pressed ? "darkgreen" : root.hovered ? "forestgreen" : "green"
        radius: 10
    }
}
