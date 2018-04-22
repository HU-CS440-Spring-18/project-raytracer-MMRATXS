#include "vector.h"

Vec::Vec(){
    x=y=z=0;
}

Vec::Vec(double a, double b, double c){
    x=a;
    y=b;
    z=c;
}

double Vec::returnX(){
    return x;
}

double Vec::returnY(){
    return y;
}

double Vec::returnZ(){
    return z;
}

double Vector::dot(Vec v){
    return (v.x*x+v.y*y+v.z*z);
}

Vec Vec::operator-(Vec v){
    return Vec(x-v.x,y-v.y,z-v.z);
}

Vec Vec::operator+(Vec v){
    return Vec(x+v.x,y+v.y,z+v.z);
}

Vec Vec::negative(){
    return Vec(-x,-y,-z);
}

Vec Vec::scale(double factor){
    return Vec(x*factor,y*factor,z*factor);
}