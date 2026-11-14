import QtQuick
import QtQuick3D

// One region drawn as its axes and its metric: the near side has three space
// axes and a clock, the far side has one space axis and three time axes. The
// frame's size follows the metric's scale factor, so it shrinks to nothing at
// the threshold and reappears with the opposite sign beyond it.
Node {
    id: frame

    property bool farSide: false
    property real metricScale: 1.0
    property var atoms: []
    property var radii: []
    property real atomScale: 55.0
    property color spaceColor: "#5aa9ff"
    property color timeColor: "#ffb14a"
    property real axisLength: 120.0
    property bool occupied: true

    readonly property real visualScale: Math.max(Math.abs(metricScale), 0.02)
    readonly property bool flipped: metricScale < 0

    scale: Qt.vector3d(visualScale, visualScale, visualScale)

    // The three same-signed axes of the region, which carry free motion.
    Repeater3D {
        model: 3
        Model {
            source: "#Cylinder"
            scale: Qt.vector3d(0.02, frame.axisLength / 100.0, 0.02)
            eulerRotation: index === 0 ? Qt.vector3d(0, 0, 90)
                         : index === 1 ? Qt.vector3d(0, 0, 0)
                         : Qt.vector3d(90, 0, 0)
            materials: PrincipledMaterial {
                baseColor: frame.farSide ? frame.timeColor : frame.spaceColor
                roughness: 0.6
            }
        }
    }

    // The one axis of the opposite sign: the near-side clock, or the far
    // side's single space axis r.
    Model {
        source: "#Cylinder"
        position: Qt.vector3d(0, -frame.axisLength * 0.9, 0)
        scale: Qt.vector3d(0.035, frame.axisLength * 0.5 / 100.0, 0.035)
        eulerRotation: Qt.vector3d(0, 0, 90)
        materials: PrincipledMaterial {
            baseColor: frame.farSide ? frame.spaceColor : frame.timeColor
            roughness: 0.4
            emissiveFactor: Qt.vector3d(0.2, 0.2, 0.2)
        }
    }

    // A grid plane whose tint says which sign the metric has here.
    Model {
        source: "#Rectangle"
        eulerRotation: Qt.vector3d(-90, 0, 0)
        scale: Qt.vector3d(frame.axisLength / 40.0, frame.axisLength / 40.0, 1)
        opacity: 0.25
        materials: PrincipledMaterial {
            baseColor: frame.flipped ? "#8a2a2a" : "#2a4a8a"
            roughness: 1.0
            alphaMode: PrincipledMaterial.Blend
        }
    }

    // The traveller's atoms, each at the coordinates the library gives it.
    Repeater3D {
        model: frame.atoms.length
        Model {
            source: "#Sphere"
            position: Qt.vector3d(frame.atoms[index].x * frame.atomScale,
                                  frame.atoms[index].y * frame.atomScale,
                                  frame.atoms[index].z * frame.atomScale)
            scale: Qt.vector3d(frame.radii[index] * frame.atomScale / 50.0,
                               frame.radii[index] * frame.atomScale / 50.0,
                               frame.radii[index] * frame.atomScale / 50.0)
            materials: PrincipledMaterial {
                baseColor: index === 0 ? "#dddddd" : "#ffffff"
                roughness: 0.3
            }
        }
    }

    // A point particle has no atoms; it is drawn as a single bright sphere.
    Model {
        visible: frame.occupied && frame.atoms.length === 0
        source: "#Sphere"
        scale: Qt.vector3d(0.25, 0.25, 0.25)
        materials: PrincipledMaterial {
            baseColor: "#ffffff"
            emissiveFactor: Qt.vector3d(0.8, 0.8, 0.8)
        }
    }
}
