import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.0
import ExImOperationType 1.0


/*
  import QtQuick.Dialogs 1.2
  ...qml/QtQuick/Dialogs/DefaultFileDialog.qml:210:25:
QML ListView: Binding loop detected for property "model"
https://bugreports.qt.io/browse/QTBUG-53707
*/
ToolBar {
    id: item
    property int operation: ExImOperationType.ExportJson
    signal accepted(int operation, string path)

    FileDialog {
        id: fileDialog
        onAccepted: {
            controller.exportImport(operation, fileDialog.file)
        }
    }

    RowLayout {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Button {
            text: qsTr("Import JSON")
            onClicked: {
                operation = ExImOperationType.ImportJson
                item.openFileDialog()
            }
        }
        Button {
            text: qsTr("Export JSON")
            onClicked: {
                operation = ExImOperationType.ExportJson
                item.openFileDialog()
            }
        }
        Button {
            text: qsTr("Import XML")
            onClicked: {
                operation = ExImOperationType.ImportXml
                item.openFileDialog()
            }
        }
        Button {
            text: qsTr("Export XML")
            onClicked: {
                operation = ExImOperationType.ExportXml
                item.openFileDialog()
            }
        }
    }

    function openFileDialog() {
        switch (operation) {
        case ExImOperationType.ImportJson:
            fileDialog.title = "select the file to import"
            fileDialog.fileMode = FileDialog.OpenFile
            fileDialog.nameFilters = ["JSON file (*.json)"]
            break
        case ExImOperationType.ExportJson:
            fileDialog.title = "select the file to export"
            fileDialog.fileMode = FileDialog.SaveFile
            fileDialog.nameFilters = ["JSON file (*.json)"]
            break
        case ExImOperationType.ImportXml:
            fileDialog.title = "select the file to import"
            fileDialog.fileMode = FileDialog.OpenFile
            fileDialog.nameFilters = ["XML file (*.xml)"]
            break
        case ExImOperationType.ExportXml:
            fileDialog.title = "select the file to export"
            fileDialog.fileMode = FileDialog.SaveFile
            fileDialog.nameFilters = ["XML file (*.xml)"]
            break
        default:
            console.log("Select unknown operation")
        }
        fileDialog.open()
    }
}
