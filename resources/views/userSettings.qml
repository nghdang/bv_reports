import QtQuick 2.0
import QtQml 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

import "../components"

Item {
    id: root

    ListView {
        id: menuListView
        anchors.fill: parent
        clip: true
        spacing: 10
        model: userSettingsViewModel.itemModel
        delegate: UserSettingsMenu {
            id: menuDelegate
            width: root.width
            spacing: 10
            menuText: settingId
            valueDelegate: UserSettingsValue {
                width: menuDelegate.width - 2 * menuDelegate.spacing
                spacing: 10
                model: valueModel
                onSettingChanged: (settingId, settingValue) => userSettingsViewModel.onSettingChanged(
                                      settingId, settingValue)
            }
        }

        ScrollBar.vertical: ScrollBar {
            height: 3
        }
    }
}
