cmake_minimum_required(VERSION 3.16)
project(quest)

include_directories(
    ../objects
)

set(CPP_SOURCES
    Quest.cpp
)

set(HPP_SOURCES
    Quest.hpp
)


add_library(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${HPP_SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    "../objects"
)