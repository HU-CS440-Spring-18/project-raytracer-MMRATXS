#pragma once
#include "vector.h"

struct Ray{

    public:
    Vec origin; // origin
    Vec direction; // direction
    Ray();
    Ray(Vec,Vec);
    Vec returnOrigin();
    Vec returnDirection();

};