#include <iostream>
#include <gtest/gtest.h>

#include "vector.hpp"

TEST(constructors, all) {
    ASSERT_NO_THROW(my_stl::vector <int> v);
    my_stl::vector <int> v1;
    ASSERT_EQ(v1.size(), 0);
    ASSERT_EQ(v1.capacity(), 0);

    ASSERT_ANY_THROW(my_stl::vector <int> v(-10));
    ASSERT_NO_THROW(my_stl::vector <int> v(10));
    my_stl::vector <int> v2(10);
    ASSERT_EQ(v2.size(), 10);
    ASSERT_EQ(v2.capacity(), 16);

    my_stl::vector <int> v = {10, 12, -1};
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}