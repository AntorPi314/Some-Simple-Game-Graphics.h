#include <graphics.h>
#include <iostream>
using namespace std;
int page=0;
int cx=20, cy=379;
void start();

void backgroud() {
    cleardevice();
    setbkcolor(BLUE);
    int x=0, y=0;
    readimagefile("back.jpg", x, y, x+1200, y+700);
}

void car() {
    int x=cx, y=cy;
    readimagefile("ship.jpg", x, y, x+360, y+100);
}

void start() {
    while (1) {
        setactivepage(page);
        setvisualpage(1-page);
        if (GetAsyncKeyState(VK_UP)) {
            // cy-=20;
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            // cy+=20;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            cx -= 10;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            cx += 10;
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
    initwindow(1200,700,"Ship Game");
    backgroud();
    car();
    start();
    getch();
    closegraph();
    return 0;
}
