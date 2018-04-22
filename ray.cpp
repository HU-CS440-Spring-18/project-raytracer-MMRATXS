#include "ray.h"

Ray::Ray(){
    origin = Vec(0,0,0);
    direction = Vec(1,0,0);
}

Ray::Ray(Vec i, Vec j){
    origin=i;
    direction=j;
}

Vec Ray::returnOrigin(){
    return origin;
}

Vec Ray::returnDirection(){
    return direction;
}