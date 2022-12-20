cmake_minimum_required(VERSION 3.16)
project(my_asserts_lib)

set(SOURCES
    Series.cpp
    State.cpp
)

add_library(${PROJECT_NAME}
    ${SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ../include
)