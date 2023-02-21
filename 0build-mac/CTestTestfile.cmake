# CMake generated Testfile for 
# Source directory: /Users/zwy/CppProject/VidManPlat
# Build directory: /Users/zwy/CppProject/VidManPlat/0build-mac
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_ffmpeg]=] "/Users/zwy/CppProject/VidManPlat/bin/test_ffmpeg")
set_tests_properties([=[test_ffmpeg]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/zwy/CppProject/VidManPlat/CMakeLists.txt;50;add_test;/Users/zwy/CppProject/VidManPlat/CMakeLists.txt;0;")
subdirs("src")
subdirs("test")
