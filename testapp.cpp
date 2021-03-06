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

    cout << "Test of float random generation" << endl;
    for(char i = 0; i < 50; i++)
        cout << random(0.0, 10.4) << "\t";
    cout << endl;

    cout << "Test of int random generation" << endl;
    for(char i = 0; i < 50; i++)
        cout << random(0, 10) << "\t";
    cout << endl;

    delay(5000);

    return 0;
}

bool Loop() {
    cout << "Loop()" << endl;


    return false;
}
