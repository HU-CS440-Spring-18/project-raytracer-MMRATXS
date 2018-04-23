#include "vector.h"
#include "ray.h"
#include "sphere.h"
#include "sphere.cpp"
#include "vector.cpp"
#include "ray.cpp"
#include "color.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    const int width=500;                        //screen width
    const int height=500;                       //screen height
    
    Color white(255,255,255);
    Color red(255,0,0);
    Color green(0,255,0);
    Color blue(0,0,255);

    std::ofstream out("out.ppm");               //output the .ppm file for display

    out<<"P3\n"<<width<<"\n"<<height<<"\n"<<"255\n";

    //Declaring Objects
    Sphere sp1(Vec(width/2,height/2,50),40,red);
    Sphere sp2(Vec(width/2,height/2,60),60,green.add(white).multiply(0.5));
    Sphere sp3(Vec(width/2,height/2,70),80,red.add(white).multiply(0.6));
    Sphere sp4(Vec(width/2,height/2,80),100,blue.add(white).multiply(0.2));
    
    //Adding objects to scene
    vector<Sphere> Scene;
    Scene.push_back(sp1);
    Scene.push_back(sp2);
    Scene.push_back(sp3);
    Scene.push_back(sp4);

    //Light Source
    Sphere light(Vec(0,0,-100),50,white); 

    static Color pixelColor[height][width];     //color for each pixel

    // Iterating the grid 
    for (int y=0; y<height; y++){
        for (int x=0; x<width; x++){

            Ray ray(Vec(x,y,0),Vec(0,0,1));     // Generate a ray

            double t =20000;
            double minDistance =INFINITY;
            int indx=-1;

            // Check for the nearest pbject 
            for(int i=0; i<Scene.size(); i++){
                if(Scene[i].intersect(ray,t)){
                    Vec distV = ray.origin + Scene[i].center;
                    double dist= distV.magnitude();
                    if(dist<minDistance){
                        minDistance = dist;
                        indx=i;
                    }
                }
            }
            // Coloring
            if(indx>-1 && Scene[indx].intersect(ray,t)){
                Vec POI = ray.origin + ray.direction.negative().scale(t);  // POint of intersection
                Vec L = light.center - POI;
                Vec N = Scene[indx].getNormal(POI).negative();

                double dt= L.normalize().dot(N.normalize());
                pixelColor[x][y] = (Scene[indx].getColor()).multiply(dt);

                if(pixelColor[x][y].r<0)pixelColor[x][y].r=0;
                if(pixelColor[x][y].g<0)pixelColor[x][y].g=0;
                if(pixelColor[x][y].b<0)pixelColor[x][y].b=0;
                if(pixelColor[x][y].r>255)pixelColor[x][y].r=255;
                if(pixelColor[x][y].g>255)pixelColor[x][y].g=255;
                if(pixelColor[x][y].b>255)pixelColor[x][y].b=255;
            }

            out<<(int)pixelColor[x][y].r << std::endl;
            out<<(int)pixelColor[x][y].g << std::endl;
            out<<(int)pixelColor[x][y].b << std::endl;
        }   
    }
    
    return 0;
}