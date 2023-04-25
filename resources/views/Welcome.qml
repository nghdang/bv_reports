import QtQuick 2.0
import QtQuick.Controls 2.0

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
        text: "Welcome to BV-BSH team"
    }

    Label {
        id: continueLabel
        anchors.top: welcomeLabel.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: 20
        color: "darkgrey"
        text: "Click here to continue"

        SequentialAnimation {

            running: true
            loops: Animation.Infinite

            NumberAnimation {
                target: continueLabel
                property: "opacity"
                duration: 1000
                easing.type: Easing.InOutQuad
                from: 0.5
                to: 1.0
            }
            NumberAnimation {
                target: continueLabel
                property: "opacity"
                duration: 1000
                easing.type: Easing.InOutQuad
                from: 1.0
                to: 0.5
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: mainWindowViewModel.enterFirstUse()
        }
    }
}
