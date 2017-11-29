import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Dialog {
    id: dialogAppend
    title: qsTr("Добавление новой записи")
    standardButtons: StandardButton.Ok | StandardButton.Cancel

    signal complete(string name, string phone, string country)

    Column {
        height: parent.height
        width: parent.width
        spacing: 10

        Column {
            width: parent.width
            Label {
                text: qsTr("Name")
            }

            TextField {
                id: name
                width: parent.width
                validator: RegExpValidator {
                    regExp: /[a-zA-Z,]{1,20}/
                }
            }
        }

        Column {
            width: parent.width
            Label {
                text: qsTr("Phone")
            }

            TextField {
                id: phone
                width: parent.width
                validator: IntValidator {
                }
            }
        }

        Column {
            width: parent.width
            Label {
                text: qsTr("Country")
            }

            ComboBox {
                id: country
                width: parent.width

                model: ListModel {
                    ListElement {
                        text: "USA"
                    }
                    ListElement {
                        text: "Russia"
                    }
                    ListElement {
                        text: "Ukraine"
                    }
                }
            }
        }
    }
    onAccepted: {
        if (name.text == "" || phone.text == "" || country.text == "") {
            dialogError.title = qsTr("Ошибка ввода")
            dialogError.text = qsTr("Введены некоректные данные")
            dialogError.open()
        } else {
            complete(name.text, phone.text, country.currentText)
            clear()
        }
    }
    onRejected: {
        clear()
    }
    function clear() {
        name.text = ""
        phone.text = ""
    }
}
