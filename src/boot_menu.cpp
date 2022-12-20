#include <iostream>
#include <string>

#include "boot_menu.hpp"

bool boot_menu(Settings & settings) {
    std::string answer;
    std::cout << "would you like to play [y/n]: ";

    while (true) {
        std::cin >> answer;
        if (answer == "n" || answer == "no") {
            std::cout << "goodbye!" << std::endl;
            return false;
        } else if (answer == "y" || answer == "yes") {
            std::cout << "let's start!" << std::endl;
            return true;
        }
        std::cout << "wrong input!";
    }
}