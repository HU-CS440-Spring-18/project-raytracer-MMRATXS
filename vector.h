#pragma once
#include <iostream>

using namespace std;

struct Vec{

    public:

    double x,y,z;

    //constructors
    Vec();
    Vec(double a,double b,double c);
    
    //functions
    double returnX();
    double returnY();
    double returnZ();
    double dot(Vec v);
    Vec operator -(Vec v);
    Vec operator +(Vec v);
    Vec negative();
    Vec scale (double factor);
};