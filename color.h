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
    Color multiply(double factor){
        return Color(r*factor,g*factor,b*factor);
    }
    Color add(Color col){
        return Color((r+col.r)/2,(g+col.g)/2,(b+col.b)/2);
    }
};