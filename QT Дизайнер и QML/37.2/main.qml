import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Player")

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 5

        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: parent.height * 0.7
            Layout.minimumHeight: 150
            color: "steelblue"
        }

        RowLayout
        {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.2
            Layout.maximumHeight: 50
            Layout.minimumHeight: 20
            width: parent.width

            Button
            {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.24
                Layout.minimumWidth: 100
                Layout.fillHeight: true
                text: "\u25B6"
                palette.button: "#0078D7"
                palette.buttonText: "white"
                font.pixelSize: parent.height * 0.8
                font.family: "Arial"
                onClicked: model.revert()
            }

            Button
            {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.24
                Layout.minimumWidth: 100
                Layout.fillHeight: true
                text: "\u23F8"
                palette.button: "#0078D7"
                palette.buttonText: "white"
                font.pixelSize: parent.height * 0.8
                font.family: "Arial"
                onClicked: model.revert()
            }

            Button
            {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.24
                Layout.minimumWidth: 100
                Layout.fillHeight: true
                text: "\u23EA"
                palette.button: "#0078D7"
                palette.buttonText: "white"
                font.pixelSize: parent.height * 0.8
                font.family: "Arial"
                onClicked: model.revert()
            }

            Button
            {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.24
                Layout.minimumWidth: 100
                Layout.fillHeight: true
                text: "\u23E9"
                palette.button: "#0078D7"
                palette.buttonText: "white"
                font.pixelSize: parent.height * 0.8
                font.family: "Arial"
                onClicked: model.revert()
            }
        }

        Slider
        {
            Layout.preferredWidth: parent.width
            Layout.fillHeight: true
            Layout.minimumHeight: 40
            Layout.minimumWidth: 400
        }
    }
}
