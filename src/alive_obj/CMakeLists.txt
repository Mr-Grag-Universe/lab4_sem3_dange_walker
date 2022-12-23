cmake_minimum_required(VERSION 3.16)
project(alive_objects)

include_directories(
    ../objects
    ../loot
    ./dialog
    ./quest
)

set(CPP_SOURCES
    Character.cpp
    Skeleton.cpp
    Slime.cpp
    Sidorovich.cpp
)

set(HPP_SOURCES
    alive.hpp
    Alive.hpp
    Character.hpp
    NPC.hpp
    Skeleton.hpp
    Slime.hpp
    Trader.hpp
    Sidorovich.hpp
)

add_subdirectory(dialog)
add_subdirectory(quest)

add_library(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${HPP_SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    "../objects"
    "../weapon"
    "../loot"
    "./dialog"
    "./quest"
)
target_link_libraries(${PROJECT_NAME}
    dialog
    quest
    loot
)