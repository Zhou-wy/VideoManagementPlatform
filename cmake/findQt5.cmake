
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux ")

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    ##################### find Qt5 start #################################
    set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")
    find_package(Qt5 COMPONENTS
            Core
            Gui
            Widgets
            REQUIRED)
    set(Qt5_Libs Qt5::Core
                Qt5::Gui
                Qt5::Widgets)
    ##################### find Qt5 finish #################################
else()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif()
