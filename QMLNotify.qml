import Qt 4.6

Rectangle {
    width: 150
    height: 150
    color: "#ffffff"

    Text {
        id: text
        x: 10
        y: 41
        width: 133
        height: 100
        text: "Hello!"
        styleColor: "#000000"
    }

    Text {
        id: headerText
        x: 10
        y: 10
        width: 133
        height: 20
        color: "#ffffff"
        text: "Header"
    }
    effect: Opacity {
    }
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#000000"
        }

        GradientStop {
            position: 1
            color: "#ffffff"
        }
    }
    rotation: 0
}
