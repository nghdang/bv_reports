import QtQuick 2.0
import QtQuick.Window 2.0

import "../components"

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: mainWindowViewModel.title
    color: "black"

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
        height: parent.height - headerBar.height - 10
        anchors.top: headerBar.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        source: {
            switch (mainWindowViewModel.activeViewName) {
            case "UserSettings":
                return "qrc:/views/UserSettings.qml"
            default:
                return "qrc:/views/UserSettings.qml"
            }
        }
    }
}
