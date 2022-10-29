#ifndef COLLIDER_STRUCT
#define COLLIDER_STRUCT

typedef struct Collider {
    double velocity = 0;
    double moving_angle = 0;
    double acceleration = 0;
    double mass = 0;
    bool mobility = false;
    bool destructibility = false;
} Collider;

#endif