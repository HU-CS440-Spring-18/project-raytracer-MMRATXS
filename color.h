#pragma once

struct Color{
    double r,g,b;
    Color(){
        r=g=b=0;
    }
    Color(double i,double j,double k){
        r=i;
        g=j;
        b=k;
    }
};