cmake_minimum_required(VERSION 3.16)
project(game_project)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(
        -Werror
        -Wall
)


include_directories(src)

add_subdirectory(src)
add_subdirectory(test)