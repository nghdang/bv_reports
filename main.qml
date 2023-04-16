import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: menuListView
        anchors.fill: parent
        clip: true
        spacing: 10
        model: userSettingsViewModel.itemModel
        delegate: menuDelegate

        ScrollBar.vertical: ScrollBar {
            height: 3
        }
    }

    Component {
        id: menuDelegate

        Column {
            width: 640
            spacing: 10

            Row {
                height: 50
                spacing: 10

                Rectangle {
                    id: menuButton
                    width: 50
                    height: 50

                    Image {
                        id: menuButtonImage
                        anchors.centerIn: parent
                        source: "qrc:/right_arrow_46.png"
                        state: "closed"
                        states: [
                            State {
                                name: "closed"
                                PropertyChanges {
                                    target: menuButtonImage
                                    source: "qrc:/right_arrow_46.png"
                                }
                            },
                            State {
                                name: "openned"
                                PropertyChanges {
                                    target: menuButtonImage
                                    source: "qrc:/down_arrow_46.png"
                                }
                            }
                        ]
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (valueLoader.visible) {
                                menuButtonImage.state = "closed"
                                valueLoader.visible = false
                            } else {
                                menuButtonImage.state = "openned"
                                valueLoader.visible = true
                            }
                        }
                    }
                }

                Rectangle {
                    id: menu
                    width: 140
                    height: 50
                    border.color: "blue"
                    border.width: 2
                    radius: 10

                    Text {
                        id: menuText
                        anchors.centerIn: parent
                        font.bold: true
                        font.pixelSize: 22
                        text: settingId
                    }
                }
            }

            Loader {
                id: valueLoader
                anchors.left: parent.left
                anchors.leftMargin: 30
                visible: false
                sourceComponent: valueLoaderSource
                onStatusChanged: {
                    if (status == Loader.Ready) {
                        item.model = valueModel
                    }
                }
            }
        }
    }

    Component {
        id: valueLoaderSource

        Column {
            property alias model: valueRepeater.model
            width: 400
            spacing: 10

            Repeater {
                id: valueRepeater
                model: valueModel
                delegate: Row {
                    spacing: 10
                    height: 50

                    Rectangle {
                        id: label
                        width: 140
                        height: 50
                        border.color: "blue"
                        border.width: 2
                        radius: 10

                        Text {
                            id: menuText
                            anchors.centerIn: parent
                            font.bold: true
                            font.pixelSize: 22
                            text: settingId
                        }
                    }

                    Rectangle {
                        id: value
                        width: 300
                        height: 50
                        border.color: "green"
                        border.width: 2
                        radius: 10
                    }
                }
            }
        }
    }
}
