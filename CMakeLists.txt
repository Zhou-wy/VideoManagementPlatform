cmake_minimum_required(VERSION 3.20)
project(VideoManPlat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#cmake在编译过程中打印编印信息
set(CMAKE_VERBOSE_MAKEFILEON ON)

# 设置输出bin文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(QRC_SOURCE_FILES src/resource.qrc src/qss.qrc)
# find QT5
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")
# Qt5
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp
        ${QRC_FILES} )

target_link_libraries(${PROJECT_NAME} vidManPlatUi
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

