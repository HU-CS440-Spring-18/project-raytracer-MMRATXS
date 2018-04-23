#include "sphere.h"

Sphere::Sphere(){
}

Sphere::Sphere(Vec i, double j, Color col){
    center=i;
    radius=j;
    color = col;
}

bool Sphere::intersect(Ray ray, double &t){
    
    Vec oc = ray.origin-center;
    double b= 2*(oc.dot(ray.direction));
    double c= oc.dot(oc)-(radius*radius);
    double disc = (b*b) -4*c;

    if(disc<0){
        return false;
    }
    else{
        disc =sqrt(disc);
        double t0 = -b-disc;
        double t1 = -b+disc;

        t= (t0<t1) ? t0:t1;
        return true;
    }
}

Vec Sphere::getNormal(Vec POI){
    return ((center-POI).scale(1/radius));   
}

Color Sphere::getColor(){
    return color;   
}