cmake_minimum_required(VERSION 3.8)

project(ordbot)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11")

list(APPEND LD_LIBRARY_PATH "/usr/local/lib")

find_package(MRPT 2.10.0 REQUIRED gui img)

aux_source_directory(src SRC_LIST)

add_executable(ordbot ${SRC_LIST})

set_target_properties(ordbot PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(ordbot PRIVATE
    mrpt::gui
    mrpt::img
)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/art)

add_custom_command(TARGET ordbot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E cat "${CMAKE_SOURCE_DIR}/art/build_success.art"
    COMMENT "Build succeeded!"
)
