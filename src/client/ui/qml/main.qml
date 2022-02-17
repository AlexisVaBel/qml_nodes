import QtQuick 2.12

import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("...zzz")

    ColumnLayout{
        Label{
            id: label1
            text: qsTr("some1")
        }

        TextEdit{
            id: edit1
            width: 120
            height: 48
            color: "black"
        }
        TextEdit{
            id: edit2
        }
        TextEdit{
            id: edit3
        }
        CheckBox{
            id: check1
        }
    }
}
