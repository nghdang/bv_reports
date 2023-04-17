import QtQuick 2.0
import QtQuick.Window 2.0

import "../components"

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: mainWindowViewModel.title

    HeaderBar {
        id: headerBar
        width: parent.width
        height: 50
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        headerBarModel: mainWindowViewModel.headerBarModel
        onSettingButtonClicked: mainWindowViewModel.enterUserSettings()
    }

    Loader {
        id: contentLoader
        width: parent.width
        height: parent.height - headerBar.height
        anchors.top: headerBar.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        source: {
            switch (mainWindowViewModel.activeViewName) {
            case "UserSettings":
                return "qrc:/views/userSettings.qml"
            default:
                return "qrc:/views/userSettings.qml"
            }
        }
    }
}
