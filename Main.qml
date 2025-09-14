import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 1200
    height: 700
    visible: true
    title: "Report Creator"

    header: TabBar {
        id: tabBar
        width: parent.width

        TabButton {
            text: "Юзабилити тестирование шапки"
        }

        TabButton {
            text: "Проверка Опыта пользователя (UX)"
        }
    }
    SplitView {
        anchors.fill: parent
        orientation: Qt.Horizontal

        // Левая часть - 2/3 ширины
        Rectangle {
            color: "lightgray"
            SplitView.preferredWidth: parent.width * 2 / 3
            SplitView.minimumWidth: 200
            Layout.fillHeight: true

            Label {
                text: "Enter GUID: "
                anchors.left: parent.left
                TextField {
                    id: guidInput
                    placeholderText: "Enter GUID here"
                    anchors.left: parent.left
                    anchors.top: parent.bottom
                    anchors.topMargin: 10
                    width: 300
                }
            }

        }

        // Правая часть - 1/3 ширины
        Rectangle {
            color: "lightgray"
            SplitView.preferredWidth: parent.width * 1 / 3
            SplitView.minimumWidth: 150
            Layout.fillHeight: true

        }
    }

}
