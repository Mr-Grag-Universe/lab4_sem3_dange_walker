#ifndef WALL_CLASS
#define WALL_CLASS

#include "Object.hpp"

class Wall : public Obj {
public:
    ObjectType get_type() {
        return WALL;
    }
    ~Wall() {
        
    }
protected:
private:
};

#endif