#ifndef ENV_CLASS
#define ENV_CLASS

#include "../objects/GameObject.hpp"

class Environment;

class Environment : public GameObj {
private:
public:
    Environment() {}
    ~Environment() {}
    void read(std::ifstream & file);
};

#endif