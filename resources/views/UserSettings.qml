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

    Button {
        id: saveButton
        width: 120
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr("Save")
        hoverEnabled: true
        contentItem: Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            text: saveButton.text
            font.bold: true
            font.pixelSize: 22
            color: "white"
        }
        background: Rectangle {
            border.color: "transparent"
            border.width: 2
            color: saveButton.down ? "darkgreen" : saveButton.hovered ? "forestgreen" : "green"
            radius: 10
        }
        onClicked: {
            focus = true
            userSettingsViewModel.onSave()
        }
    }
}
