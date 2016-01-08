#include "graphicdisplay.h"

#include <iostream>
#include <sstream>

using namespace std;

GraphicDisplay::GraphicDisplay(int n): View(n) {
    
    xw = new Xwindow(500, 500);
    theDisplay = new char *[n];
    for (int i = 0; i < n; ++i) {
        theDisplay[i] = new char [n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            theDisplay[i][j] = '0';
        }
    }
}

GraphicDisplay::~GraphicDisplay() {
    for (int i = 0; i < gridSize; i++) {
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
    delete xw;
}

void GraphicDisplay::notify(int r, int c, char ch) {
    theDisplay[r][c] = ch;
}

void GraphicDisplay::print(std::ostream &out) {
    int x;
    int y;
    int width;
    int height;
    char colours;
    
    for (int i = 0; i < gridSize; i++) {
        x = i * (500 / gridSize);
        height = 500 / gridSize;
        for (int j = 0; j < gridSize; j++) {
            y = j * (500 / gridSize);
            width = 500 / gridSize;
            colours = theDisplay[i][j];
            if (colours == '0') xw->fillRectangle(x, y, width, height, Xwindow::White);
            if (colours == '1') xw->fillRectangle(x, y, width, height, Xwindow::Black);
            if (colours == '2') xw->fillRectangle(x, y, width, height, Xwindow::Red);
            if (colours == '3') xw->fillRectangle(x, y, width, height, Xwindow::Green);
            if (colours == '4') xw->fillRectangle(x, y, width, height, Xwindow::Blue);
        }
    }
}
