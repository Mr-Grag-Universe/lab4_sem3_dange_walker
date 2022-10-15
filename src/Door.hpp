#ifndef DOOR_CLASS
#define DOOR_CLASS

#include "Object.hpp"

class Door : public Obj {
public:
    ObjectType get_type() {
        return DOOR;
    }
    ~Door() {
        
    }
};

#endif