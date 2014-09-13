import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("GA tutorial")

    Column {
        spacing: 20
        anchors.centerIn: parent
        Button {
            text: "Send Hit"
            onClicked: { gAnalytics.sendHit("myView")}
        }
        Button {
            text: "Send Event"
            onClicked: { gAnalytics.sendEvent("Category", "Action", "Label", 1) }
        }
    }
}
