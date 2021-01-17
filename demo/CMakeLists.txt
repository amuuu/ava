add_executable (AvaDemo EngineSampleMain.cpp ${CMAKE_SOURCE_DIR}/src/include/portaudio.h )

target_link_libraries (AvaDemo LINK_PUBLIC Ava)