cmake_minimum_required(VERSION 3.16)
project(loot)

set(CPP_SOURCES
    Money.cpp
    Coins.cpp
)

set(HPP_SOURCES
    Money.hpp
)

include_directories(
    ../objects
)

add_library(${PROJECT_NAME} ${CPP_SOURCES} ${HPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE
    ../objects
)