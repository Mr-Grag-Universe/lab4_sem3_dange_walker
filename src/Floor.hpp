#ifndef FLOOR_CLASS
#define FLOOR_CLASS

#include "Object.hpp"

class Floor : public Obj {
public:
    ObjectType get_type() {
        return FLOOR;
    }
    ~Floor() {
        
    }
protected:
private:
};

#endif