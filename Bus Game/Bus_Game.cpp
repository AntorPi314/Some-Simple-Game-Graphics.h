#include <graphics.h>
#include <iostream>
using namespace std;
int page=0;
int cx=370, cy=550;
void start();

void backgroud() {
    cleardevice();
    setbkcolor(GREEN);
    cleardevice();
}

void car() {
    int x=cx, y=cy;
    readimagefile("bus.jpg", x, y, x+90, y+233);
}

void start() {
    while (1) {
        setactivepage(page);
        setvisualpage(1-page);
        if (GetAsyncKeyState(VK_UP)) {
            cy-=20;
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            cy+=20;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            cx -= 20;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
                cx += 20;
        }
        backgroud();
        car();

        page=1-page;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(800,700,"Bus");
    backgroud();
    car();
    start();
    getch();
    closegraph();
    return 0;
}
