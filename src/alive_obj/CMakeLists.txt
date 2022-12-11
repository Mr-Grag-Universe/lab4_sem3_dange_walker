cmake_minimum_required(VERSION 3.16)
project(alive_objects)

include_directories(../objects)

set(CPP_SOURCES
    Character.cpp
    Skeleton.cpp
    Slime.cpp
)

set(HPP_SOURCES
    alive.hpp
    Alive.hpp
    Character.hpp
    NPC.hpp
    Skeleton.hpp
    Slime.hpp
)

add_library(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${HPP_SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    "../objects"
    "../weapon"
)