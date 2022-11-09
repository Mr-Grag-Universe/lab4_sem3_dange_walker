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

    my_stl::vector <int> v3 = {10, 12, -1};
    ASSERT_EQ(v3.size(), 3);
    ASSERT_EQ(v3.capacity(), 4);

    my_stl::vector <int> v4(v3);
    ASSERT_EQ(v4.size(), 3);
    ASSERT_EQ(v4.capacity(), 4);

    my_stl::vector <int> v5(std::move(v3));
    ASSERT_EQ(v5.size(), 3);
    ASSERT_EQ(v5.capacity(), 4);
    [[maybe_unused]] size_t s{};
    ASSERT_EQ(v3.size(), 0);
    ASSERT_EQ(v3.capacity(), 0);
}

TEST(methods, get_el) {
    my_stl::vector <int> v = {0, 2, -1, 3};
    // ASSERT_ANY_THROW(v[1714] = 10); - ловит segfault
    ASSERT_EQ(v[0], 0);
    ASSERT_EQ(v[3], 3);
    v[2] = -10;
    ASSERT_EQ(v[2], -10);

    // компилятор ругается. тест не требуется))
    // const my_stl::vector <int> & v1 = v;
    // ASSERT_ANY_THROW(v1[1]);
}

TEST(methods, push_back) {
    my_stl::vector <int> v;
    v.push_back(10);
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v.capacity(), 1);
    v.push_back(-12);
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v.capacity(), 2);
}

TEST(methods, pop_back) {
    my_stl::vector <int> v = {1, 2, 3, 6};
    v.pop_back();
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v.capacity(), 4);
    my_stl::vector <int> v1;
    ASSERT_ANY_THROW(v1.pop_back());
    v1.push_back(1);
    ASSERT_EQ(v1.size(), 1);
    ASSERT_EQ(v1.capacity(), 1);
    v1.pop_back();
    ASSERT_EQ(v1.size(), 0);
    ASSERT_EQ(v1.capacity(), 1);
}

TEST(methods, empty) {
    my_stl::vector <int> v = {1, 2, 3, 6};
    ASSERT_FALSE(v.empty());
    my_stl::vector <int> v1;
    ASSERT_TRUE(v1.empty());
}

TEST(operators, assignment) {
    my_stl::vector <int> v = {1, 2, 3, 6};
    my_stl::vector <int> v1 = {7, 8, 9};
    v = std::move(v1);
    ASSERT_EQ(v.capacity(), 4);
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v[1], 8);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}