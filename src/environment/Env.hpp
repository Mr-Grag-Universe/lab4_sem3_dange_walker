#ifndef ENV_CLASS
#define ENV_CLASS

#include "../Object.hpp"

class Environment;

class Environment : public Obj<GameTypeSystem> {
private:
    /* data */
public:
    Environment() {}
    ~Environment() {}
    void read(std::ifstream & file);
};


#endif