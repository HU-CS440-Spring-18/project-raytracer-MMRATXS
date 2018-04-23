#pragma once
#include "vector.h"
#include "ray.h"
#include "math.h"
#include "color.h"

struct Sphere{

    public:

    // Variables
    Vec center; // center
    double radius; // radius
    Color color;
    bool reflective;
    double reflectiveIndex;

    // Constructors
    Sphere();
    Sphere(Vec, double, Color);
    
    // Functions
    bool intersect(Ray ray, double &t);
    Vec getNormal(Vec POI);
    Color getColor();

};