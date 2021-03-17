add_executable (AvaStructuredDemo EngineSampleMain.cpp ${CMAKE_SOURCE_DIR}/src/include/portaudio.h )

target_link_libraries (AvaStructuredDemo LINK_PUBLIC Ava)