#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;


void plotEllipsePoints(int x, int y, int cx, int cy) {
    putpixel(cx + x, cy + y, WHITE);  
    putpixel(cx - x, cy + y, WHITE);  
    putpixel(cx + x, cy - y, WHITE);  
    putpixel(cx - x, cy - y, WHITE);  
}


void midpointEllipse(int cx, int cy, int a, int b) {
    int x = 0;
    int y = b;
    
    int a2 = a * a;
    int b2 = b * b;
    
    int dx = 2 * b2 * x;
    int dy = 2 * a2 * y;
    
    
    int p1 = b2 - a2 * b + (a2 / 4);
    
    plotEllipsePoints(x, y, cx, cy);
    
    while (dx < dy) {
        x++;
        dx += 2 * b2;
        
        if (p1 < 0) {
            p1 += b2 + dx;
        } else {
            y--;
            dy -= 2 * a2;
            p1 += b2 + dx - dy;
        }
        
        plotEllipsePoints(x, y, cx, cy);
    }
    
    int p2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    
    while (y > 0) {
        y--;
        dy -= 2 * a2;
        
        if (p2 > 0) {
            p2 += a2 - dy;
        } else {
            x++;
            dx += 2 * b2;
            p2 += a2 - dy + dx;
        }
        
        plotEllipsePoints(x, y, cx, cy);
    }
}

int main() {
    int gd = DETECT, gm;
    int cx, cy, a, b;

    initgraph(&gd, &gm, "");

    cout << "Enter the center coordinates (cx, cy): ";
    cin >> cx >> cy;
    cout << "Enter the horizontal radius (a): ";
    cin >> a;
    cout << "Enter the vertical radius (b): ";
    cin >> b;

    midpointEllipse(cx, cy, a, b);

    getch();
    closegraph();
    return 0;
}

