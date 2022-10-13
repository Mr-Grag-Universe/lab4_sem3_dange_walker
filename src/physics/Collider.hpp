#ifndef COLLIDER_STRUCT
#define COLLIDER_STRUCT

typedef struct Collider {
    double velocity;
    double moving_angle;
    double acceleration;
    double mass;
    bool mobility;
    bool destructibility;
} Collider;

#endif