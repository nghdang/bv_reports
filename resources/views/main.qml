import QtQuick 2.0
import QtQuick.Window 2.0

import "../components"

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: mainWindowViewModel.title

    Item {
        id: headerContainer
        width: parent.width
        height: 50
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        HeaderBar {
            id: headerBar
            anchors.fill: parent
            headerBarModel: mainWindowViewModel.headerBarModel
            onSettingButtonClicked: mainWindowViewModel.enterUserSettings()
        }
    }

    Item {
        id: contentContainer
        width: parent.width
        height: parent.height - headerContainer.height
        anchors.top: headerContainer.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle {
            anchors.fill: parent
            color: "lightgreen"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("mainWindowViewModel:" + mainWindowViewModel)
                    console.log("mainWindowViewModel.headerBarModel:"
                                + mainWindowViewModel.headerBarModel)
                }
            }
        }
    }
}
