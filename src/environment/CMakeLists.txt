cmake_minimum_required(VERSION 3.16)
project(environment)

include_directories(../objects)

set(CPP_SOURCES
    Env.cpp
    Door.cpp
    Floor.cpp
    Wall.cpp
)

set(HPP_SOURCES
    environment.hpp
    Env.hpp
    Door.hpp
    Floor.hpp
    Wall.hpp
)

add_library(${PROJECT_NAME} 
    ${CPP_SOURCES}
    ${HPP_SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    "../objects"
)