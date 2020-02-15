#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

struct coordinatePoint{
    int x,y;
};

bool compareFunctionForSort(coordinatePoint center, coordinatePoint A,coordinatePoint B){
    int distanceOfA = ((A.x-center.x)*(A.x-center.x))+((A.y-center.y)*(A.y-center.y));
    int distanceOfB = ((B.x-center.x)*(B.x-center.x))+((B.y-center.y)*(B.y-center.y));
    if(distanceOfA<=distanceOfB) return true;
    else return false;
}

bool checkIsDestination(coordinatePoint A,coordinatePoint B){
    if(A.x>B.x or A.y>B.y) return true;
    else return false;
}

void drawVerticalLine(int y0,int y1,int x){
    if(y0>y1) swap(y0,y1);
    for(int y=y0;y<=y1;y++) putpixel(x,y,RED);
}

void drawHorizontalLine(int x0,int x1,int y){
    if(x0>x1) swap(x0,x1);
    for(int x=x0;x<=x1;x++) putpixel(x,y,GREEN);
}

void drawUpwardLine(int d,int ds,int dt,int x,int y,int limit){
    while(x<=limit){
        putpixel(x,y,WHITE);
        if(d<0) d+=ds;
        else{
            y++;
            d+=dt;
        }
        x++;
    }
}

void drawDownwardPositiveLine(int d,int ds,int dt,int x,int y,int limit){
    while(x>=limit){
        putpixel(x,y,WHITE);
        if(d<0) d+=ds;
        else{
            y++;
            d+=dt;
        }
        x--;
    }
}

void drawDownwardNegativeLine(int d,int ds,int dt,int x,int y,int limit){
    while(x<=limit){
        putpixel(x,y,WHITE);
        if(d>0) d+=ds;
        else{
            y--;
            d+=dt;
        }
        x++;
    }
}

void drawNaturalLine(coordinatePoint A,coordinatePoint B){
    int dx = B.x-A.x, dy = B.y-A.y;
    int dt = 2*(dy-dx), ds = 2*dy;
    int d = 2*dy-dx;

    int x = A.x,y = A.y;
    if(dx>0 and dy>0) drawUpwardLine(d,ds,dt,x,y,B.x);
    else{
        if(dy<0) drawDownwardNegativeLine(d,ds,dt,x,y,B.x);
        else drawDownwardPositiveLine(d,ds,dt,x,y,B.x);
    }
}

void bresenhamLineDrawing(coordinatePoint A,coordinatePoint B){
    if(A.x==B.x) drawVerticalLine(A.y,B.y,A.x);
    else if(A.y==B.y) drawHorizontalLine(A.x,B.x,A.y);
    else {
        if(checkIsDestination(A,B)) swap(A,B);
        drawNaturalLine(A,B);
    }
}

int main(){
    int gm=0,gd=DETECT;
    initgraph(&gd,&gm,"SIR");

    while(true){
        coordinatePoint A,B;
        scanf("%d %d %d %d",&A.x,&A.y,&B.x,&B.y);
        bresenhamLineDrawing(A,B);
    }
    getchar();
    closegraph();
    return 0;
}
