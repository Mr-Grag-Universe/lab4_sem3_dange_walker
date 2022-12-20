#ifndef BOOT_MENU_HEADER
#define BOOT_MENU_HEADER

#include "enums/Complexity.hpp"

struct Settings {
    Complexity complexity = EASY;
};

bool boot_menu(Settings & settings);

#endif // BOOT_MENU_HEADER