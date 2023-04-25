import QtQuick 2.0
import QtQuick.Window 2.0

import "../components"

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: Constants.APPLICATION_TITLE
    color: "black"

    HeaderBar {
        id: headerBar
        width: parent.width
        height: 50
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        visible: mainWindowViewModel.activeViewName !== Constants.VIEW_NAME_WELCOME
        headerBarModel: mainWindowViewModel.headerBarModel
        onSettingIconClicked: mainWindowViewModel.enterUserSettings()
    }

    Loader {
        id: contentLoader
        width: parent.width
        height: parent.height - headerBar.height - 10
        anchors.top: headerBar.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        source: {
            let sourceUrl
            switch (mainWindowViewModel.activeViewName) {
            case Constants.VIEW_NAME_USER_SETTINGS:
                sourceUrl = "qrc:/views/UserSettings.qml"
                break
            case Constants.VIEW_NAME_FIRST_USE:
                sourceUrl = "qrc:/views/FirstUse.qml"
                break
            default:
                sourceUrl = "qrc:/views/Welcome.qml"
                break
            }
            return sourceUrl
        }
    }
}
