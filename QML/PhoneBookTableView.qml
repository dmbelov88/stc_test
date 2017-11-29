import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

TableView {
    id: tableView

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            dialogAppend.open()
        }
    }

    Component.onCompleted: {
        if (rowCount == 0)
            mouseArea.enabled = true
        else
            mouseArea.enabled = false
    }

    TableViewColumn {
        role: "name"
        title: "Name"
        width: 0.375 * tableView.viewport.width
    }
    TableViewColumn {
        role: "phone"
        title: "Phone"
        width: 0.375 * tableView.viewport.width
    }
    TableViewColumn {
        role: "country"
        title: "Country"
        width: 0.25 * tableView.viewport.width
    }
    model: personTableModel

    rowDelegate: Rectangle {
        anchors.fill: parent
        color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white')
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton | Qt.LeftButton
            onClicked: {
                tableView.selection.clear()
                tableView.selection.select(styleData.row)
                tableView.currentRow = styleData.row
                tableView.focus = true
                if (mouse.button === Qt.RightButton) {
                    rowContextMenu.popup()
                }
            }
        }
    }

    onRowCountChanged: {
        if (rowCount == 0)
            mouseArea.enabled = true
        else
            mouseArea.enabled = false
    }

    Menu {
        id: rowContextMenu
        MenuItem {
            text: qsTr('Добавить')
            onTriggered: {
                dialogAppend.open()
            }
        }
        MenuItem {
            text: qsTr('Удалить')
            onTriggered: {
                dialogDelete.open()
            }
        }
    }

    MessageDialog {
        id: dialogDelete
        title: qsTr("Удаление записи")
        text: qsTr("Подтвердите удаление записи")
        icon: StandardIcon.Warning
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        onAccepted: {
            controller.removeRecord(personTableModel.getId(
                                        tableView.currentRow),
                                    tableView.currentRow)
        }
    }

    MessageDialog {
        id: dialogError
        icon: StandardIcon.Warning
        standardButtons: StandardButton.Ok
    }

    AppendRecordDialog {
        id: dialogAppend
        onComplete: {
            controller.insertRecord(name, phone, country)
            mouseArea.enabled = false
        }
    }
}
