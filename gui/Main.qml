import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick3D
import QtQuick3D.Helpers
import Superluminal

ApplicationWindow {
    id: window
    width: 1400
    height: 860
    visible: true
    title: "Superluminal Threshold"
    color: "#0b0e14"

    JourneyModel {
        id: journey
        objectName: "journey"
        Component.onCompleted: {
            travellerIndex = startTraveller
            senseIndex = startSense
            progress = startProgress
            if (autoplaySeconds > 0) {
                secondsPerTrip = autoplaySeconds
                progress = 0
                play()
            }
        }
    }

    // The two frames sit either side of the threshold. The far side's space
    // axis is drawn at full length for the chosen distance, so the marker's
    // position along it is r over that distance.
    readonly property real nearX: -260
    readonly property real farX: 260
    readonly property real rAxisHalf: 130

    View3D {
        id: view
        anchors.fill: parent
        environment: SceneEnvironment {
            clearColor: window.color
            backgroundMode: SceneEnvironment.Color
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        PerspectiveCamera {
            id: camera
            position: Qt.vector3d(0, 220, 640)
            eulerRotation: Qt.vector3d(-18, 0, 0)
            clipFar: 5000
        }

        DirectionalLight {
            eulerRotation: Qt.vector3d(-45, 30, 0)
            brightness: 1.2
        }
        DirectionalLight {
            eulerRotation: Qt.vector3d(30, -120, 0)
            brightness: 0.5
        }

        // The near-side universe: three space axes, one clock. It shrinks with
        // cos 2theta as the traveller accelerates and reappears mirrored.
        UniverseFrame {
            id: nearFrame
            position: Qt.vector3d(window.nearX, 0, 0)
            farSide: false
            metricScale: journey.metricScale
            atoms: journey.onFarSide ? [] : journey.nearAtoms
            radii: journey.atomRadii
            occupied: !journey.onFarSide
        }

        // The far-side universe: three time axes, one space axis r. Its metric
        // is the near one with every sign reversed, so it is drawn at minus the
        // same scale: full and mirrored at the start, collapsed at the
        // threshold, full in its own sign beyond it.
        UniverseFrame {
            id: farFrame
            position: Qt.vector3d(window.farX, 0, 0)
            farSide: true
            metricScale: -journey.metricScale
            atoms: journey.onFarSide ? journey.farAtoms : []
            radii: journey.atomRadii
            occupied: journey.onFarSide
        }

        // The threshold, cos 2theta = 0, as a translucent sheet between them.
        Model {
            source: "#Rectangle"
            position: Qt.vector3d(0, 40, 0)
            scale: Qt.vector3d(0.12, 3.2, 1)
            opacity: 0.18 + 0.5 * Math.max(0, 1 - Math.abs(journey.metricScale) * 6)
            materials: PrincipledMaterial {
                baseColor: "#ffffff"
                emissiveFactor: Qt.vector3d(1, 1, 1)
                alphaMode: PrincipledMaterial.Blend
            }
        }

        // The far side's space axis r, long enough to show the drive, and the
        // traveller's marker moving along it: r carries the near clock.
        Model {
            source: "#Cylinder"
            position: Qt.vector3d(window.farX, -110, 0)
            scale: Qt.vector3d(0.02, window.rAxisHalf * 2 / 100, 0.02)
            eulerRotation: Qt.vector3d(0, 0, 90)
            materials: PrincipledMaterial { baseColor: "#5aa9ff"; roughness: 0.5 }
        }
        Model {
            source: "#Sphere"
            visible: journey.onFarSide
            position: Qt.vector3d(window.farX + journey.r / journey.farDistance * window.rAxisHalf, -110, 0)
            scale: Qt.vector3d(0.18, 0.18, 0.18)
            materials: PrincipledMaterial {
                baseColor: journey.senseIndex === 0 ? "#ff6a6a" : "#8f8"
                emissiveFactor: Qt.vector3d(0.6, 0.6, 0.6)
            }
        }

        // The near-side clock hand, turned by the clock shift alone: it stands
        // still until the drive along r moves it, backward or forward.
        Node {
            position: Qt.vector3d(window.nearX, -110, 0)
            Model {
                source: "#Cylinder"
                scale: Qt.vector3d(0.9, 0.02, 0.9)
                materials: PrincipledMaterial { baseColor: "#1c2230"; roughness: 0.9 }
            }
            Model {
                source: "#Cube"
                position: Qt.vector3d(0, 2, -18)
                scale: Qt.vector3d(0.03, 0.03, 0.36)
                eulerRotation: Qt.vector3d(0, 0, 0)
                materials: PrincipledMaterial {
                    baseColor: journey.nearClockShiftNs < 0 ? "#ff6a6a" : "#ffb14a"
                    emissiveFactor: Qt.vector3d(0.4, 0.4, 0.4)
                }
            }
            eulerRotation: Qt.vector3d(0, -journey.nearClockShiftNs / Math.max(Math.abs(journey.finalShiftNs), 1e-9) * 300, 0)
        }

        AxisHelper { enableXZGrid: true; enableAxisLines: false; gridOpacity: 0.12 }
    }

    // Controls
    Rectangle {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 16
        width: 320
        height: controls.implicitHeight + 24
        color: "#cc10141c"
        radius: 8
        border.color: "#334"

        ColumnLayout {
            id: controls
            anchors.fill: parent
            anchors.margins: 12
            spacing: 8

            Text { text: "Traveller"; color: "#aaa" }
            ComboBox {
                Layout.fillWidth: true
                model: journey.travellerNames
                currentIndex: journey.travellerIndex
                onActivated: function(index) { journey.reset(); journey.travellerIndex = index }
            }

            Text { text: "Direction in time"; color: "#aaa" }
            ComboBox {
                Layout.fillWidth: true
                model: ["Backward: drive along +r", "Forward: drive along -r"]
                currentIndex: journey.senseIndex
                onActivated: function(index) { journey.reset(); journey.senseIndex = index }
            }

            Text { text: "Far-side distance, metres"; color: "#aaa" }
            SpinBox {
                id: distanceBox
                Layout.fillWidth: true
                from: 1; to: 1000
                value: Math.round(journey.farDistance)
                onValueModified: { journey.reset(); journey.farDistance = value }
                Connections {
                    target: journey
                    function onInputChanged() { distanceBox.value = Math.round(journey.farDistance) }
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Button {
                    Layout.fillWidth: true
                    text: journey.playing ? "Pause" : (journey.progress >= 1 ? "Play again" : "Play")
                    font.bold: true
                    onClicked: journey.togglePlay()
                }
                Button { text: "Reset"; onClicked: journey.reset() }
            }

            Slider {
                id: progressSlider
                Layout.fillWidth: true
                from: 0; to: 1
                value: journey.progress
                onMoved: { journey.pause(); journey.progress = value }
                Connections {
                    target: journey
                    function onSampleChanged() {
                        if (!progressSlider.pressed) progressSlider.value = journey.progress
                    }
                }
            }

            Text {
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                color: "#ccc"
                font.pixelSize: 12
                text: "Every number on screen is read from the library the check suite runs. Space is drawn in blue, time in orange; the sheet in the middle is cos 2theta = 0."
            }
        }
    }

    Hud {
        model: journey
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 16
    }

    // Phase ribbon along the bottom.
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 16
        width: Math.min(parent.width - 32, 1100)
        height: 54
        color: "#cc10141c"
        radius: 8
        border.color: "#334"
        RowLayout {
            anchors.fill: parent
            anchors.margins: 6
            spacing: 6
            Repeater {
                model: journey.phaseCount
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    radius: 4
                    color: index === journey.phaseIndex ? "#2a4a8a" : "#1a2030"
                    border.color: index === journey.phaseIndex ? "#5aa9ff" : "#2a3040"
                    Text {
                        anchors.centerIn: parent
                        text: (index + 1)
                        color: "#fff"
                        font.pixelSize: 16
                    }
                }
            }
        }
    }

    Shortcut { sequence: "Space"; onActivated: journey.togglePlay() }
}
