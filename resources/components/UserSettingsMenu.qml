import QtQuick 2.0
import QtGraphicalEffects 1.0

import "../components"

Column {
    property alias menuText: menuText.text
    property alias valueDelegate: valueLoader.sourceComponent

    Row {
        height: 50
        spacing: 10

        Item {
            id: menuButton
            width: 50
            height: parent.height

            Image {
                id: menuButtonImage
                anchors.centerIn: parent
                state: "collapsed"
                states: [
                    State {
                        name: "collapsed"
                        PropertyChanges {
                            target: menuButtonImage
                            source: "qrc:/graphics/RIGHT_ARROW_SICON.png"
                        }
                    },
                    State {
                        name: "uncollapsed"
                        PropertyChanges {
                            target: menuButtonImage
                            source: "qrc:/graphics/DOWN_ARROW_SICON.png"
                        }
                    }
                ]
            }

            ColorOverlay {
                anchors.fill: menuButtonImage
                source: menuButtonImage
                color: "green"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueLoader.visible) {
                        menuButtonImage.state = "collapsed"
                        valueLoader.visible = false
                    } else {
                        menuButtonImage.state = "uncollapsed"
                        valueLoader.visible = true
                    }
                }
            }
        }

        Text {
            id: menuText
            width: 140
            height: parent.height
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pixelSize: 26

            MouseArea {
                anchors.fill: parent
                onDoubleClicked: {
                    if (valueLoader.visible) {
                        menuButtonImage.state = "collapsed"
                        valueLoader.visible = false
                    } else {
                        menuButtonImage.state = "uncollapsed"
                        valueLoader.visible = true
                    }
                }
            }
        }
    }

    Loader {
        id: valueLoader
        anchors.left: parent.left
        visible: false
    }
}
