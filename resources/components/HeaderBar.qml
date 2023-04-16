import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    property var headerBarModel
    signal settingButtonClicked

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
            source: headerBarModel.LOGO_ICON
        }

        ColorOverlay {
            id: logoImageColor
            anchors.fill: logoImage
            source: logoImage
            color: "green"
        }
    }

    /* Right to left icons */
    Item {
        id: settingButtonContainer
        width: parent.height
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        Image {
            id: settingButtonImage
            anchors.centerIn: parent
            source: headerBarModel.SETTINGS_ICON
        }

        ColorOverlay {
            id: settingButtonImageColor
            anchors.fill: settingButtonImage
            source: settingButtonImage
            state: "released"
            states: [
                State {
                    name: "released"
                    PropertyChanges {
                        target: settingButtonImageColor
                        color: "blue"
                    }
                },
                State {
                    name: "pressed"
                    PropertyChanges {
                        target: settingButtonImageColor
                        color: "lightblue"
                    }
                }
            ]
        }

        MouseArea {
            id: settingButtonMouseArea
            anchors.fill: parent
            onPressed: {
                settingButtonImageColor.state = "pressed"
            }
            onReleased: {
                settingButtonImageColor.state = "released"
                settingButtonClicked()
            }
        }
    }

    Item {
        id: currentTimeContainer
        width: 200
        height: parent.height
        anchors.right: settingButtonContainer.left
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: currentTimeText
            anchors.centerIn: parent
            font.pixelSize: 22
            text: headerBarModel.currentTime
        }
    }
}
