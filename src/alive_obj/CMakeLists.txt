cmake_minimum_required(VERSION 3.16)
project(alive_objects)

include_directories(../objects)

add_library(${PROJECT_NAME}
    Character.cpp
    Skeleton.cpp
    Slime.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
    "../objects"
    "../weapon"
)