project(g_tests)

# set(gtest_SOURCE_DIR ../../../test/googletest-main/gtest)

set(VECTOR_SRC
    vector_tests.cpp
)

# add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/../include ${gtest_SOURCE_DIR})
include_directories(../../include)

add_executable(g_tests_vector ${VECTOR_SRC})
target_link_libraries(g_tests_vector gtest gtest_main vector)