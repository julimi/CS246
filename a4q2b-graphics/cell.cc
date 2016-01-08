#include <iostream>

#include "cell.h"
#include "game.h"

using namespace std;

void Cell::notifyNeighbours() {
    // get through all of neighbours and notify them
    for (int i = 0; i < numNeighbours; i++) {
        neighbours[i]->notify(state, prevState);
    } // for
} // notifyNeighbours

void Cell::notifyGame() {
    // point to the 4-parameters notify func
    game->notify(r,c,prevState,state);
} // notifyGame

// ctor
Cell::Cell(): state(0), prevState(0), numNeighbours(0), r(0), c(0) {}  // Cell()

char Cell::getState() {
    // get the current state of char style
    return state + '0';
} // getState

void Cell::setState(const int &change) {
    
    // update the current state to previous state
    prevState = state;
    
    // change becomes the current state
    state = change;
    
} // setState

void Cell::setCoords(const int r, const int c) {
    
    // update coordinates
    this->r = r;
    this->c = c;
    
} // setCoords

void Cell::setGame(Game * game) {
    
    // update game
    this->game = game;
    
} // setGame

void Cell::addNeighbour(Cell *neighbour) {
    
    // add the neighbour inside the range of num of neighbours
    if (numNeighbours < maxNeighbours)
        neighbours[numNeighbours++] = neighbour;   // exit
    
} // addNeighbour

void Cell::notify(const int &change) {
    
    // if the change is different with state
    if (change != state) {
        
        // set the new state and tell all neighbours and the game
        setState(change);
        notifyNeighbours();
        notifyGame();
        
    } // exit
    
} // notify(int)

void Cell::notify(const int &current,const int &previous) {
    
    // if the previous equals to private state
    // set the new state by current
    if (state == previous) notify(current);
    
} // notify(int, int)
