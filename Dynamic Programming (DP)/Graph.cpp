#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    circle(200, 200, 50);
    outtextxy(150, 260, "Hello C++ Graphics");

    getch();
    closegraph();
    return 0;
}
