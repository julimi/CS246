#include <iostream>

#include "game.h"


void Game::clearGame() {
    if (theGrid != 0) {
        
        // delete pointers in array
        for (int i = 0; i < gridSize; i++) {
            delete [] theGrid[i];
        } // for
        
        // delete pointer to pointer
        delete [] theGrid;
        
        // reset them to 0
        notification = 0;
        theGrid = 0;
        gridSize = 0;
        
    } // exit
} // clearGame

// ctor
Game::Game(): theGrid(0), gridSize(0), notification(0){}  // Game()

// dtor
Game::~Game() {
    clearGame();
} // ~Game

void Game::notify(int r, int c, unsigned int oldState, unsigned int newState) {
    
    // tell gamenotification that the state colout gonna change
    notification->notify(r, c, newState);
    
    // decre the oldstate colour appearence
    colours[oldState]--;
    
    // incre the newstate colour appearence
    colours[newState]++;
    
} // notify(int, int, unsigned int, unsigned int)

bool Game::isWon() {
    
    // if there is any one colour take up all grid
    // win the game
    for (int i = 0; i < 5; i++) {
        if (colours[i] == gridSize * gridSize) return true;
    } // for
    return false;
    
} // isWon

void Game::init(int n, GameNotification *gameNotification) {
    
    // clear the old game
    clearGame();
    
    // set new gridSize as n
    gridSize = n;
    
    // new notification
    notification = gameNotification;
    
    // set new pointer to pointer
    theGrid = new Cell *[gridSize];
    // set new arrays pointed by theGrid
    for (int i = 0; i < gridSize; i++) {
        theGrid[i] = new Cell [gridSize];
    } // for
    // set each Cell
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            theGrid[i][j].setGame(this);
            theGrid[i][j].setState(0);
            theGrid[i][j].setCoords(i, j);
        }
    } // for
    // add neighbours of each cell inside the square of gridSize * gridSize
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (i-1 >= 0) theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
            if (j-1 >= 0) theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
            if (i+1 < gridSize) theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
            if (j+1 < gridSize) theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
        } // for
    } // for
    
    // initialize the colours appearence
    for (int i = 1; i < 5; i++) {
        colours[i] = 0;
    } // for
    // same colour taking up all grid firstly
    colours[0] = gridSize * gridSize;
    
} // init(int, GameNotification)


void Game::change(const int &c) {
    
    // (0,0) cell and all its neighbours gonna change
    theGrid[0][0].notify(c);
    
} // change

void Game::init(int r, int c, int change) {
    
    // if coordinate is not in the grid, exit the func
    if (r >= gridSize || c >= gridSize || r < 0 || c < 0) return;
    
    // if the state is inside 5 colours:
    if (change >= 0 && change <= 4) {
        
        // decre the previous state(previous current state) appearence first
        colours[theGrid[r][c].getState() - '0']--;
        
        // set the new state for the Cell
        theGrid[r][c].setState(change);
        
        // incre the new state appearence
        colours[change]++;
        
        // notify that the state change
        notification->notify(r, c, change);
        
    } // exit
    
} // init(int,int,int)
