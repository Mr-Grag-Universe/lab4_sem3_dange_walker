#include <iostream>

#include "DialogTree.hpp"
#include "../../libs/simpleini/SimpleIni.h"

void DialogTree::load_from_file(fs::path path) {
    CSimpleIniA ini;
	ini.SetUnicode();

    SI_Error rc = ini.LoadFile(path.c_str());
    if (rc < 0) {
        std::cout << "error in reading of dialog from: " << path << std::endl;
        throw std::runtime_error("cannot open this .ini file to read dialog");
    }

    // get all sections
	CSimpleIniA::TNamesDepend sections;
	ini.GetAllSections(sections);

	// get all keys in a section
	CSimpleIniA::TNamesDepend keys;
	ini.GetAllKeys("Hello", keys);
    
    for (auto key : keys) {
        const char * str = ini.GetValue("Hello", key.pItem);
        std::cout << str << std::endl;
        dialog_list.push_back(std::string(str));
    }
}

std::string DialogTree::next_phrase() {
    std::string str = dialog_list.front();
    dialog_list.pop_front();
    return str;
}