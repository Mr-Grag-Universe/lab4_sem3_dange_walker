cmake_minimum_required(VERSION 3.16)
project(events)

set(CPP_SOURCES
    Event.cpp
    Kill.cpp
)

set(HPP_SOURCES
    event.hpp
    Event.hpp
    Kill.hpp
)

add_library(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${HPP_SOURCES}
)