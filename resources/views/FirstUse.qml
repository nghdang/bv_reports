import QtQuick 2.0
import QtQuick.Controls 2.0

import "../components"

Item {
    id: root

    Label {
        id: welcomeLabel
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: 36
        color: "lightgrey"
        text: "This is FirstUse"
    }

    ControlButton {
        id: nextButton
        width: 120
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr("Next")
        onClicked: {
            mainWindowViewModel.enterUserSettings()
        }
    }
}
