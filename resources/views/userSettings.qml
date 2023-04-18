import QtQuick 2.0
import QtQml 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

import "../components"

Item {
    id: root

    ListView {
        id: menuListView
        width: parent.width
        anchors.top: parent.top
        anchors.bottom: saveButton.top
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        spacing: 10
        cacheBuffer: 1000
        model: userSettingsViewModel.itemModel
        delegate: UserSettingsMenu {
            id: menuDelegate
            width: root.width
            spacing: 10
            menuText: settingLabel
            valueDelegate: UserSettingsValue {
                width: menuDelegate.width - 2 * menuDelegate.spacing
                spacing: 10
                model: valueModel
                onSettingChanged: userSettingsViewModel.onSettingChanged(
                                      settingId, settingValue)
            }
        }

        ScrollBar.vertical: ScrollBar {
            height: 3
        }
    }

    Rectangle {
        id: saveButton
        width: 120
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        radius: 10
        state: "released"
        states: [
            State {
                name: "released"
                PropertyChanges {
                    target: saveButton
                    color: "green"
                }
            },
            State {
                name: "pressed"
                PropertyChanges {
                    target: saveButton
                    color: "darkgreen"
                }
            },
            State {
                name: "hovered"
                PropertyChanges {
                    target: saveButton
                    color: "forestgreen"
                }
            }
        ]

        Text {
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 22
            color: "white"
            text: qsTr("Save")
        }

        MouseArea {
            id: saveButtonMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: saveButton.state = "hovered"
            onExited: saveButton.state = "released"
            onPressed: saveButton.state = "pressed"
            onReleased: {
                saveButton.state = "released"
                focus = true
                userSettingsViewModel.onSave()
            }
        }
    }
}
