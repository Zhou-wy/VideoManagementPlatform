cmake_minimum_required(VERSION 3.20)
project(vidManPlatUi)

# find QT5
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_subdirectory(cpuMonitor)
add_subdirectory(iconHelper)
add_subdirectory(videoPanel)
add_subdirectory(playFFmpeg)

set(EXTRA_LIBS ${EXTRA_LIBS} CpuMonitor IconHelper VideoPanel PlayFFmpeg)

qt_add_resources(resource.qrc)
add_library(${PROJECT_NAME} sevimanplat.cpp sevimanplat.h sevimanplat.ui)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${EXTRA_LIBS}
        )