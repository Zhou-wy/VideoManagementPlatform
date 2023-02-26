#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "yaml-cpp" for configuration ""
set_property(TARGET yaml-cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(yaml-cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libyaml-cpp.0.7.0.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libyaml-cpp.0.7.dylib"
  )

list(APPEND _cmake_import_check_targets yaml-cpp )
list(APPEND _cmake_import_check_files_for_yaml-cpp "${_IMPORT_PREFIX}/lib/libyaml-cpp.0.7.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
