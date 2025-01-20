#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;


void plotCirclePoints(int x, int y, int cx, int cy) {
    putpixel(cx + x, cy + y, WHITE);  
    putpixel(cx - x, cy + y, WHITE);  
    putpixel(cx + x, cy - y, WHITE);  
    putpixel(cx - x, cy - y, WHITE);  
    putpixel(cx + y, cy + x, WHITE);  
    putpixel(cx - y, cy + x, WHITE);  
    putpixel(cx + y, cy - x, WHITE);  
    putpixel(cx - y, cy - x, WHITE);  
}


void midpointCircle(int cx, int cy, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;  

   
    plotCirclePoints(x, y, cx, cy);

  
    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;  
        } else {
            y--;
            p = p + 2 * (x - y) + 1;  
        }
        plotCirclePoints(x, y, cx, cy);
    }
}

int main() {
    int gd = DETECT, gm;
    int cx, cy, r;

   
    initgraph(&gd, &gm, "");

    
    cout << "Enter the center coordinates (cx, cy): ";
    cin >> cx >> cy;
    cout << "Enter the radius: ";
    cin >> r;

   
    midpointCircle(cx, cy, r);

    
    getch();
    closegraph();
    return 0;
}

