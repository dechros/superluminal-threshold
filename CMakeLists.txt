cmake_minimum_required(VERSION 3.28)

project(superluminal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SLM_WARNINGS -Wall -Wextra -Wpedantic)

# The layers, lowest first. Each library links only the layer below it, and
# the include root is the same for all, so the direction of dependence is
# enforced by tools/check_layers.py as a test rather than by the compiler.
#
#   core      linear algebra and the report
#   physics   metrics, dispersion, the wall, the scan, the involution, units
#   particle  constant-force trajectories and the coordinate map
#   journey   travellers, round trips, ways across, the sampler
#   checks    one Section per library, and the executable that runs them
#   gui       the Qt Quick 3D viewer, which reads journey only

function(slm_layer name)
    file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/${name}/*.cpp)
    add_library(slm_${name} STATIC ${sources})
    target_include_directories(slm_${name} PUBLIC ${CMAKE_SOURCE_DIR}/src)
    target_compile_options(slm_${name} PRIVATE ${SLM_WARNINGS})
endfunction()

slm_layer(core)
slm_layer(physics)
slm_layer(particle)
slm_layer(journey)

target_link_libraries(slm_physics PUBLIC slm_core)
target_link_libraries(slm_particle PUBLIC slm_physics)
target_link_libraries(slm_journey PUBLIC slm_particle)

file(GLOB_RECURSE SLM_CHECK_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/checks/*.cpp)
add_library(slm_checks STATIC ${SLM_CHECK_SOURCES})
target_include_directories(slm_checks PUBLIC ${CMAKE_SOURCE_DIR}/checks)
target_link_libraries(slm_checks PUBLIC slm_journey)
target_compile_options(slm_checks PRIVATE ${SLM_WARNINGS})

add_executable(superluminal app/main.cpp)
target_link_libraries(superluminal PRIVATE slm_checks)
target_compile_options(superluminal PRIVATE ${SLM_WARNINGS})

option(SLM_GUI "Build the Qt Quick 3D viewer" ON)

if(SLM_GUI)
    find_package(Qt6 6.8 COMPONENTS Quick Quick3D QuickControls2)
    if(Qt6_FOUND)
        add_subdirectory(gui)
    else()
        message(STATUS "Qt 6 not found, the viewer is skipped")
    endif()
endif()

enable_testing()
add_test(NAME suite COMMAND superluminal)
find_package(Python3 COMPONENTS Interpreter)
if(Python3_FOUND)
    add_test(NAME layering
             COMMAND ${Python3_EXECUTABLE} -I ${CMAKE_SOURCE_DIR}/tools/check_layers.py ${CMAKE_SOURCE_DIR})
endif()
