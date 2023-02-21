# CMake generated Testfile for 
# Source directory: /home/zwy/CWorkspace/VidManPlat
# Build directory: /home/zwy/CWorkspace/VidManPlat/0build-linux
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_ffmpeg "/home/zwy/CWorkspace/VidManPlat/bin/test_ffmpeg")
set_tests_properties(test_ffmpeg PROPERTIES  _BACKTRACE_TRIPLES "/home/zwy/CWorkspace/VidManPlat/CMakeLists.txt;50;add_test;/home/zwy/CWorkspace/VidManPlat/CMakeLists.txt;0;")
subdirs("src")
subdirs("test")
