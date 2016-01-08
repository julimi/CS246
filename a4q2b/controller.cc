#include "controller.h"
#include "game.h"
#include "textdisplay.h"
// Uncomment for part (b)
//#include "graphicdisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ctor
Controller::Controller(){
    game = new Game();
    td = NULL;
// TODO - for part (b)
} // Controller()

/*
 * Update the View(s) to indicate the new game state
*/
void Controller::notify(int r, int c, unsigned int state){
    
    // change state to char style,
    // and point to notify(int,int,char) of textdisplay(view)
    td->notify(r, c, state + '0');
    
} // notify(int,int,unsigned int)

/*
 * Called when command init is received
*/
void Controller::init(istream & input, Game & g){
    int i;
    // count the num of stdin
    int count = 0;
    // count the appearence of -1
    int replace = 0;
    // coordinates
    int r = 0;
    int c = 0;
    while (input >> i) {
        
        // meet -1 once
        if (i == -1 && replace != -1 && count%3 == 0) {
            r = i;
            replace--;
            count++;
            continue;
        } // exit
        
        // meet -1 twice
        if (i == -1 && replace == -1 && count%3 == 1) break;// exit
        // reset to 0
        replace = 0;
        // situations:
        if (count%3 == 0) r = i;
        else if (count%3 == 1) c = i;
        else {
            g.init(r, c, i);
        } // exit
        count++;
        
    } // while
} // init

bool Controller::checkWin(int movesLeft){
  if(game->isWon() && movesLeft != 0){
    cout << "Won" << endl;
    return true;
  } // exit
  return false;
} // checkWin

void Controller::play(){
  srand(time(NULL));
  int moves = 0;
  string cmd;
  bool playing = false;
  while (cin >> cmd) {
    if (cmd == "new") {
      int n;
      cin >> n; 
      game->init(n, this);
      delete td;
      td = new TextDisplay(n);
// Uncomment for part (b)
//      gd = new GraphicDisplay(n);

      moves = 0;
    } // new int
// the ? command is only needed for part (b)
// when graphics command line is enabled
//    else if (cmd == "?"){
//         cout << "White: 0" << endl;
//         cout << "Black: 1" << endl;
//         cout << "Red:   2" << endl;
//         cout << "Green: 3" << endl;
//         cout << "Blue:  4" << endl;
//
//    }

    else if (cmd == "init") {
      init(cin, *game);
      #if DEBUG
      cout << "Done initialization" << endl;
      #endif
      td->print(cout);
      if (checkWin(moves)){
        break;
      }
    } // init
    else if (cmd == "include"){
       string file;
       cin >> file;
       ifstream input(file.c_str());
       init(input, *game);
       td->print(cout);
       if (checkWin(moves)){
        break;
      }
    } // include file
    else if (cmd == "switch") {
      if (checkWin(moves)){
        break;
      }
      if(moves > 0){
        int next;
        if (cin >> next && (next >= 0 || next <= 4)){
          game->change(next);
          td->print(cout);
          --moves;
	       if (moves == 1) {
          cout << moves << " move left" << endl;
	       }
         else {
          cout << moves << " moves left" << endl;
	       }
         if(game->isWon()){
	         cout << "Won" << endl;
	         break;
	       }
 	       if(moves == 0){
  	         cout << "Lost" << endl;
	         break;
	       }
        }
        else cerr << "Invalid move" << endl;
      }
    } // switch int
    else if (cmd == "game" && !playing){
      cin >> moves;
      if (moves < 0) {
        moves = 0;
      } 
      else if (moves == 1) {
        cout << moves << " move left" << endl;
      }
      else { 
        cout << moves << " moves left" << endl;
      }
      if (checkWin(moves)){
        break;
      }
    } // game int
  } // while
} // play

// dtor
Controller::~Controller(){
    // delete pointers in the private field
    delete game;
    delete td;
    td = 0;
} // ~Controller
