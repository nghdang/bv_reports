import QtQuick 2.0
import QtQuick.Controls 2.0

Column {
    id: root

    property alias model: valueRepeater.model
    signal settingChanged(string settingId, string settingValue)

    Repeater {
        id: valueRepeater
        model: valueModel
        delegate: Row {
            spacing: 10
            height: 50

            Text {
                id: valueLabel
                width: 140
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 22
                color: "grey"
                text: settingLabel
            }

            TextField {
                id: valueValue
                width: root.width - valueLabel.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
                color: enabled ? "darkgrey" : "grey"
                background: Rectangle {
                    border.color: "transparent"
                    color: "#333"
                    radius: 10
                }
                text: settingValue
                onEditingFinished: {
                    root.settingChanged(settingId, displayText)
                }
                enabled: settingValue.length === 0 || settingId.startsWith(
                             "LeaderInfo") === false
            }
        }
    }
}
