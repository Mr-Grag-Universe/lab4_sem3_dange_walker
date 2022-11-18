project(vector)

set(SRC_FILES 
    vector.cpp
)


add_library(vector ${SRC_FILES})
target_include_directories(vector
    PRIVATE
        ${PROJECT_SOURCE_DIR}/../../include
)

# add_executable(${PROJECT_NAME} ${SRC_FILES})