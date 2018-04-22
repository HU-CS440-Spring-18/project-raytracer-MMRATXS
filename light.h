#pragma once
#include "color.h"
#include "vector.h"

class Light{

    public:
        Light();
        Light(Vector3 point, Color color);
        Color color;
        Vec point;

};