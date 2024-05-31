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
    readimagefile("back_sky.jpg", x, y, x+900, y+700);
}

void bird() {
    int x=cx, y=cy;
    readimagefile("bird.jpg", x, y, x+100, y+90);
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
            cx -= 10;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            cx += 20;
        }
        backgroud();
        bird();

        page=1-page;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(900,700,"My Bird");
    backgroud();
    bird();
    start();
    getch();
    closegraph();
    return 0;
}
