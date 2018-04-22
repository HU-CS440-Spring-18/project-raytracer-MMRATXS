#include "vector.h"
#include "ray.h"
#include "sphere.h"
#include "sphere.cpp"
#include "vector.cpp"
#include "ray.cpp"
#include "color.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    const int width=500;                        //screen width
    const int height=500;                       //screen height

    std::ofstream out("out.ppm");               //output the .ppm file for display

    out<<"P3\n"<<width<<"\n"<<height<<"\n"<<"255\n";

    Sphere sp(Vec(width/2,height/2,50),50);     // sphere object

    Color white(255,255,255);                   //coloring color: white
    Color red(255,0,0);                   //coloring color: white
    Color green(0,255,0);                   //coloring color: white
    Color blue(0,0,255);                   //coloring color: white
    static Color pixelColor[height][width];     //color for each pixel

    // Iterating the grid 
    for (int y=0; y<height; y++){
        for (int x=0; x<width; x++){

            Ray ray(Vec(x,y,0),Vec(0,0,1));     // Generate a ray

            double t =20000;

            // Check for intersections
            if(sp.intersect(ray,t)){

                Vec POI = ray.origin + ray.direction.scale(t);  // POint of intersection
                pixelColor[x][y] = red.add(white);
            }

            out<<(int)pixelColor[x][y].r << std::endl;
            out<<(int)pixelColor[x][y].g << std::endl;
            out<<(int)pixelColor[x][y].b << std::endl;
        }   
    }
    
    return 0;
}