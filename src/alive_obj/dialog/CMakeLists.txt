cmake_minimum_required(VERSION 3.16)
project(dialog)

set(SOURCES_CPP
    DialogTree.cpp
)
set(SOURCES_HPP
    DialogTree.hpp
)

add_library(${PROJECT_NAME} ${SOURCES_CPP} ${SOURCES_HPP})