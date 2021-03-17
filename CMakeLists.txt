cmake_minimum_required (VERSION 3.12)
project (Ava)

SET(AVA_COMPILE_FLAGS "-lrt -lm -lasound -pthread")
add_definitions(${AVA_COMPILE_FLAGS})
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${AVA_COMPILE_FLAGS}")

add_subdirectory (src)
add_subdirectory (simpledemo)
add_subdirectory (structureddemo)
