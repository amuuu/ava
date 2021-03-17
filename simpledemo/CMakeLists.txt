add_executable (AvaSimpleDemo main.cpp ${CMAKE_SOURCE_DIR}/src/include/portaudio.h )

target_link_libraries (AvaSimpleDemo LINK_PUBLIC Ava)