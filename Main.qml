import QtQuick
import QtQuick.Controls;

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Connection")

    Connections{
        target: cppSignalSender
        onCallQml: {
            console.log("This is Qml: callQml signal cought.")
            mText.text = parameter;
        }

        onCppTimer: {
            mRectText.text = value; //parameter name is value in the signal of the class
        }
    }

    Column{

        Rectangle{
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text {
                id: mRectText
                text: "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 30
            }

        }

        Button{
            text: "Call C++ Method"
            onClicked: {
                cppSignalSender.cppSlot();
            }
        }

       Text {
           id: mText
           text: qsTr("text")
       }
    }
}
