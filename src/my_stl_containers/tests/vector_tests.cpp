#include <iostream>
#include <gtest/gtest.h>

#include "../vector.hpp"

TEST(constructors, all) {
    ASSERT_ANY_THROW(my_stl::vector v);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}