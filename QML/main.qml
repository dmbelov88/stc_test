import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0

ApplicationWindow {
    id: application
    visible: true
    width: 640
    height: 480
    minimumWidth: toolBar.implicitWidth
    title: qsTr("STC test")

    toolBar: CustomToolBar {
        onAccepted: {
            controller.exportImport(operation, path)
        }
    }

    SplitView {
        id: splitView
        anchors.fill: parent

        PhoneBookTableView {
            id: phoneBookTableView
            height: parent.height
            width: 0.5 * parent.width
        }

        TableView {
            id: clientTable
            height: parent.height
            width: 0.5 * parent.width

            TableViewColumn {
                title: "Name"
                role: "name"
                width: 0.5 * clientTable.viewport.width
            }
            TableViewColumn {
                title: "Status"
                role: "status"
                width: 0.5 * clientTable.viewport.width
            }

            model: clientTableModel
        }
    }
}
