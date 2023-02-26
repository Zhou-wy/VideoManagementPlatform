if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(YAML_DIR ${CMAKE_SOURCE_DIR}/3rdparty/yaml-cpp0.7.7/linux)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")
    set(YAML_DIR ${CMAKE_SOURCE_DIR}/3rdparty/yaml-cpp0.7.7/windows)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(YAML_DIR ${CMAKE_SOURCE_DIR}/3rdparty/yaml-cpp0.7.7/macos)
    find_package (PkgConfig REQUIRED)
    pkg_check_modules(YAMLCPP REQUIRED yaml-cpp) # 查找yaml-cpp
else()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif()

include_directories(${YAML_DIR}/include) # 头文件搜索路径
link_directories( ${YAMLCPP_LIBRARY_DIRS}) # 动态链接库或静态链接库的搜索路径
message("YAML-CPP include dir:${YAML_DIR}/include")
message("YAML-CPP include lib:${YAML_DIR}/lib")