#pragma once
#include "vector.h"
#include "ray.h"
#include "math.h"

struct Sphere{

    public:
    Vec center; // center
    double radius; // radius
    Sphere();
    Sphere(Vec, double);

    bool intersect(Ray ray, double &t);
    Vec getNormal(Vec POI);

};