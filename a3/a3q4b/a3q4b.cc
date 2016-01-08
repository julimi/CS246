#include <iostream>
#include <fstream>
#include <string>
#include "scoreboard.h"
#include "player.h"

using namespace std;

int main() {
    
    string cmd;
    
    // create a scoreboard
    ScoreBoard* board = ScoreBoard::getScoreBoard();
	
    while (cin >> cmd) {
        
        // meet "quit", break game
		if (cmd == "quit") break;
		
        // meet "game", start the game
        else if (cmd == "game") {
			
            // create an array of string to store order
            string file[2];
            cin >> file[0] >> file[1];
			
            // store X and O
            enum PlayerName playerName[2];
			board->startNewGame();
			if (board->getTimes() % 2) {    // odd game times
				playerName[0] = X;
				playerName[1] = O;
			} else {                        // even game times, and change the order to call
				playerName[0] = O;
				playerName[1] = X;
				string temp = file[0];
				file[0] = file[1];
				file[1] = temp;
			} // exit
            
            // create 2 players
			Player* player[2];
			ifstream inputs[2];
			for (int i = 0; i < 2; i++) {
				
                if (file[i] == "stdin") {   // stdin mode
					player[i] = Player::getPlayer(cin, playerName[i], true);
				} else {                    // file input mode
					inputs[i].open(file[i].c_str());
					player[i] = Player::getPlayer(inputs[i], playerName[i], false);
				} // exit
			} // for
			int currentPlayer = 0;
            
            // if the game does not finish, the current player moves
			while (!board->hasFinish()) {
				player[currentPlayer]->makeMove();
				currentPlayer = 1 - currentPlayer;
			} // while
            
            // print the score
			board->printScore();
            
            // delete the players info
			delete player[0];
			delete player[1];
		}
	}
}
