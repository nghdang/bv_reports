import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    property var headerBarModel
    signal settingIconClicked

    /* Left to right icons */
    Item {
        id: logoContainer
        width: parent.height
        height: parent.height
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        Image {
            id: logoImage
            anchors.centerIn: parent
            source: GraphicId.ICNID_DRAGON_SYMBOL_MICON
        }

        ColorOverlay {
            id: logoImageColor
            anchors.fill: logoImage
            source: logoImage
            color: "green"
        }
    }

    /* Right to left icons */
    Button {
        id: settingIcon
        width: parent.height
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        hoverEnabled: true
        visible: headerBarModel.isSettingIconVisible
        contentItem: Item {
            id: name
            Image {
                id: settingIconImage
                anchors.centerIn: parent
                source: GraphicId.ICNID_SETTINGS_MICON
            }

            ColorOverlay {
                id: settingIconImageColor
                anchors.fill: settingIconImage
                source: settingIconImage
                color: settingIcon.pressed ? "grey" : settingIcon.hovered ? "lightgrey" : "darkgrey"
            }
        }
        background: Rectangle {
            color: "black"
        }
        onClicked: settingIconClicked()
    }

    Item {
        id: currentTimeContainer
        width: 200
        height: parent.height
        anchors.right: settingIcon.visible ? settingIcon.left : parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: currentTimeText
            anchors.centerIn: parent
            color: "lightgrey"
            font.pixelSize: 22
            text: headerBarModel.currentTime
        }
    }
}
