qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(superluminal-gui
    main.cpp
    JourneyModel.cpp
    JourneyModel.h
)

qt_add_qml_module(superluminal-gui
    URI Superluminal
    VERSION 1.0
    QML_FILES
        Main.qml
        UniverseFrame.qml
        Hud.qml
)

target_link_libraries(superluminal-gui PRIVATE slm_journey Qt6::Quick Qt6::Quick3D Qt6::QuickControls2)
target_compile_options(superluminal-gui PRIVATE -Wall -Wextra)
