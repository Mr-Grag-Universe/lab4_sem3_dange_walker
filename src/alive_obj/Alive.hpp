#ifndef ALIVE_CLASS
#define ALIVE_CLASS

#include <string>

class Alive {
private:
    std::string name;
    double health = 0;
    
public:
    Alive(/* args */);
    ~Alive();
};

Alive::Alive(/* args */) {
}

Alive::~Alive() {
}


#endif