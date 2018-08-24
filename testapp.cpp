#include "CJsMB_SDL2.cpp"
#include <iostream>

using namespace std;
using namespace JsMB;

int Main() {
    cout << "Main()" << endl;
    createWindow("My test app", 640, 480);

    cout << ctg(2) << endl;

    cls();
    fillScreen(0, 0, 255);
    setColor(255, 0, 0);
    drawRect(5, 5, 25, 25);
    repaint();

    delay(5000);

    return 0;
}

bool Loop() {
    cout << "Loop()" << endl;


    return false;
}
