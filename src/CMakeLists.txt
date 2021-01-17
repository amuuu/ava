
file(GLOB ava_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

add_library(Ava ${ava_SRC})

target_link_libraries(Ava ${CMAKE_CURRENT_SOURCE_DIR}/include/portaudio.h)

set_target_properties(Ava PROPERTIES COMPILE_DEFINITIONS BUILDER_STATIC_DEFINE)
target_link_libraries(Ava ${CMAKE_CURRENT_SOURCE_DIR}/include/libportaudio.a ${CMAKE_CURRENT_SOURCE_DIR}/include/portaudio.h)


target_include_directories(Ava PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})