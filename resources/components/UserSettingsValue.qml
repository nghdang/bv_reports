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
                id: valueText
                width: 140
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 22
                text: settingLabel
            }

            TextField {
                id: value
                width: root.width - valueText.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
                background: Rectangle {
                    border.color: "green"
                    border.width: 2
                    radius: 10
                }
                onEditingFinished: root.settingChanged(valueText.text, text)
            }
        }
    }
}
