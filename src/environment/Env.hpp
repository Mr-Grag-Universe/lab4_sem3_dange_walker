#ifndef ENV_CLASS
#define ENV_CLASS

#include "../Object.hpp"

class Environment : public Obj {
private:
    /* data */
public:
    Environment() {}
    ~Environment() {}
    void read(std::ifstream & file);
};


#endif