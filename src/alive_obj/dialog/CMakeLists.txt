cmake_minimum_required(VERSION 3.16)
project(dialog)

set(SOURCES_CPP
    DialogTree.cpp
)
set(SOURCES_HPP
    DialogTree.hpp
)

set(SIMPLE_INI_DIR ../../libs/simpleini)

add_library(${PROJECT_NAME} ${SOURCES_CPP} ${SOURCES_HPP})
add_library(simple-ini ${SIMPLE_INI_DIR}/ConvertUTF.c ${SIMPLE_INI_DIR}/ConvertUTF.h ${SIMPLE_INI_DIR}/SimpleIni.h)
target_link_libraries(${PROJECT_NAME} simple-ini)