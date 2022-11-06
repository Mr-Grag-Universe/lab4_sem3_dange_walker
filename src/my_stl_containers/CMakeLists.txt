project(my_stl)

set(SRC_FILES 
    vector.cpp
    vector.hpp
)

add_subdirectory(tests)
add_library(${PROJECT_NAME} ${SRC_FILES})
# add_executable(${PROJECT_NAME} ${SRC_FILES})