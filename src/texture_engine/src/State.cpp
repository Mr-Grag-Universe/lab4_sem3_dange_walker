#include <iostream>

#include "State.hpp"

// ============= constructors =============== //
my_asserts::State::State() {
    std::cout << "state constructor!" << std::endl;
}

// ============= getters ================//
size_t my_asserts::State::get_number() const {
    return number;
}