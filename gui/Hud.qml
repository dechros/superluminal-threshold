import QtQuick
import QtQuick.Layouts

// The numbers the trip is made of, read from the model at every frame.
Rectangle {
    id: hud

    required property var model

    color: "#cc10141c"
    radius: 8
    border.color: "#334"
    implicitWidth: 360
    implicitHeight: column.implicitHeight + 24

    function sci(value, digits) {
        return Number(value).toExponential(digits === undefined ? 3 : digits)
    }

    ColumnLayout {
        id: column
        anchors.fill: parent
        anchors.margins: 12
        spacing: 4

        Text { text: hud.model.travellerName; color: "#fff"; font.pixelSize: 20; font.bold: true }
        Text { text: hud.model.senseName; color: "#ffb14a"; font.pixelSize: 15 }
        Text {
            text: "Phase " + (hud.model.phaseIndex + 1) + " of " + hud.model.phaseCount + ": " + hud.model.phaseName
            color: "#9cf"; font.pixelSize: 14; wrapMode: Text.WordWrap; Layout.fillWidth: true
        }

        Rectangle { Layout.fillWidth: true; height: 1; color: "#334"; Layout.topMargin: 6; Layout.bottomMargin: 6 }

        GridLayout {
            columns: 2
            columnSpacing: 16
            rowSpacing: 3
            Layout.fillWidth: true

            Text { text: "Speed beta"; color: "#aaa" }
            Text { text: hud.model.beta > 1e6 ? "infinite" : hud.model.beta.toFixed(4) + " c"; color: "#fff" }

            Text { text: "Crossing angle theta"; color: "#aaa" }
            Text { text: (hud.model.theta * 180 / Math.PI).toFixed(2) + " deg"; color: "#fff" }

            Text { text: "Metric scale cos 2theta"; color: "#aaa" }
            Text {
                text: hud.model.metricScale.toFixed(4)
                color: hud.model.metricScale > 1e-3 ? "#5aa9ff" : hud.model.metricScale < -1e-3 ? "#ff6a6a" : "#ffffff"
            }

            Text { text: "Own clock rate dtau/dt"; color: "#aaa" }
            Text { text: hud.model.clockRate.toFixed(4); color: "#fff" }

            Text { text: "Momentum / hbar"; color: "#aaa" }
            Text { text: hud.sci(Math.abs(hud.model.momentum)) + " 1/s"; color: "#fff" }

            Text { text: "Demanded at light speed"; color: "#aaa" }
            Text { text: hud.sci(hud.model.thresholdMomentum) + " 1/s"; color: "#fff" }

            Text { text: "Mass parameter mu"; color: "#aaa" }
            Text { text: hud.sci(hud.model.mu) + " 1/m^2"; color: "#fff" }

            Text { text: "Far-side position r"; color: "#aaa" }
            Text { text: hud.model.r.toFixed(3) + " m"; color: "#fff" }

            Text { text: "Near-side clock"; color: "#aaa" }
            Text {
                text: (hud.model.nearClockShiftNs >= 0 ? "+" : "") + hud.model.nearClockShiftNs.toFixed(4) + " ns"
                color: hud.model.nearClockShiftNs < 0 ? "#ff6a6a" : "#8f8"
                font.bold: true
            }

            Text { text: "Shift at return"; color: "#aaa" }
            Text { text: (hud.model.finalShiftNs >= 0 ? "+" : "") + hud.model.finalShiftNs.toFixed(4) + " ns"; color: "#fff" }
        }

        Rectangle { Layout.fillWidth: true; height: 1; color: "#334"; Layout.topMargin: 6; Layout.bottomMargin: 6 }

        Text { text: "Metric diagonal g(theta)"; color: "#aaa" }
        RowLayout {
            spacing: 8
            Repeater {
                model: 4
                Text {
                    text: Number(hud.model.metric[index]).toFixed(3)
                    color: hud.model.metric[index] > 1e-3 ? "#5aa9ff" : hud.model.metric[index] < -1e-3 ? "#ff6a6a" : "#fff"
                    font.family: "monospace"
                }
            }
        }
        Text {
            text: hud.model.onFarSide
                  ? "Far side: three time axes carry x, y, z; the one space axis r carries the near clock with a minus sign."
                  : "Near side: three space axes, one time axis. Approaching light speed the metric shrinks to zero."
            color: "#ccc"; font.pixelSize: 12; wrapMode: Text.WordWrap; Layout.fillWidth: true
        }
    }
}
