add_executable (AvaStructuredDemo main.cpp ${CMAKE_SOURCE_DIR}/src/include/portaudio.h )

target_link_libraries (AvaStructuredDemo LINK_PUBLIC Ava)