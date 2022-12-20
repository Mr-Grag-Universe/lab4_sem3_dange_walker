#ifndef DIALOG_CLASS_HPP
#define DIALOG_CLASS_HPP
#include <list>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class DialogTree {
private:
protected:
    std::list<std::string> dialog_list;
public:
    DialogTree() {}

    //======== other methods =======//

    void load_from_file(fs::path);
    
    std::string next_phrase();
};

#endif // DIALOG_CLASS_HPP