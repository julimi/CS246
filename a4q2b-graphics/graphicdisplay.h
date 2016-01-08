#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__

#include <iostream>
#include <sstream>
#include "view.h"
#include "window.h"

class GraphicDisplay : public View {
    
    Xwindow * xw;
    
    char **theDisplay;          //the n x n display
    
public:
    GraphicDisplay(int n); //one arg constructor where the parameter is the gridSize
    
    ~GraphicDisplay(); //dtor
    
    /*
     * The Controller calls notify to
     * update the (r,c) location to be ch
     */
    virtual void notify(int r, int c, char ch);
    
    /*
     * Prints the grid as specified in the assignment specification.
     */
    virtual void print(std::ostream &out);
};

#endif
