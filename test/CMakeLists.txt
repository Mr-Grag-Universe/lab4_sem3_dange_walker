project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-main/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
add_executable(Google_Tests_run main_test.cpp)
include_directories(../src)
# # target_link_libraries(Google_Tests_run big_int_lib gtest gtest_main)
