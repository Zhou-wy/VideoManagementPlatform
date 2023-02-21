cmake_minimum_required(VERSION 3.20)
project(vidManPlatUi)

# find QT5
include(${CMAKE_SOURCE_DIR}/cmake/findQt5.cmake)

add_subdirectory(cpuMonitor)
add_subdirectory(iconHelper)
add_subdirectory(videoPanel)
add_subdirectory(playFFmpeg)

set(EXTRA_LIBS ${EXTRA_LIBS} CpuMonitor IconHelper VideoPanel PlayFFmpeg)

qt_add_resources(resource.qrc)
add_library(${PROJECT_NAME} sevimanplat.cpp sevimanplat.h sevimanplat.ui)

target_link_libraries(${PROJECT_NAME}
        ${Qt5_Libs}
        ${EXTRA_LIBS}
        )