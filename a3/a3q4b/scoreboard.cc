#include "scoreboard.h"
#include "player.h"
#include <iostream>

using namespace std;

ScoreBoard* ScoreBoard::board = NULL;

// get the row of board
int ScoreBoard::getRow(const string& pos) {
    // 1st row line
    if (pos.find('N') != string::npos) {
        return 0;
    }
    // 3rd row line
    else if (pos.find('S') != string::npos) {
        return 2;
    }
    // central line
    else {
        return 1;
    } // exit
} // getRow

// get the right of board
int ScoreBoard::getCol(const string& pos) {
	// 1st column line
    if (pos.find('W') != string::npos) {
        return 0;
    }
    // 3rd column line
    else if (pos.find('E') != string::npos) {
        return 2;
    }
    // central line
    else {
        return 1;
    } // exit
} // getCol

// mathod to get ctor of scoreboard
ScoreBoard* ScoreBoard::getScoreBoard() {
	if (board == NULL) {
		board = new ScoreBoard();
	} // exit
	return board;
} // getScoreBoard

// method to start game
void ScoreBoard::startNewGame() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gameBoard[i][j] = NONE;
		} // for
	} // for
	times++;          // game times increment
	inGame = true;    // determine the game is still continued
} // startNewGame

ScoreBoard::ScoreBoard() : times(0), inGame(false) {
	scores[X] = scores[O] = 0;
} // ctor

ScoreBoard::~ScoreBoard() {
} // dtor

// show the process and result of the game
void ScoreBoard::makeMove(enum PlayerName player, const string& pos, const bool& fromStdin) {
	
    // solve the fault situation of postion is taken
    if (isOccupied(pos)) {
		throw -1;
	} // exit
    
    // situation of file input
	if (!fromStdin) {
		cout << "(plays " << pos << ")" << endl;
	} // exit
    
	gameBoard[getRow(pos)][getCol(pos)] = player;
	
    // situation that someone wins
    if (hasWin(player)) {
		cout << Player::playerToStr(player) << " wins" << endl;
		scores[player]++;
		inGame = false;
	} // exit
    
    // situation that game draws and finishes
	if (checkFinish()) {
		cout << "Draw" << endl;
	} // exit
} // makeMove

// find out whether a given position is taken
bool ScoreBoard::isOccupied(const string& pos) const {
	return gameBoard[getRow(pos)][getCol(pos)] != NONE;
} // isOccupied

// determine there is anyone win
bool ScoreBoard::hasWin(enum PlayerName player) const {
	bool win;
    
    // win situation of vertical and horizontal line
	for (int i = 0; i < 3; i++) {
		win = true;
		
        // scan the col
        for (int j = 0; j < 3; j++) {
			if (gameBoard[i][j] != player) {
				win = false;
				break;
			} // exit
		} // for
		if (win) return true;
		win = true;
        
        // scan the row
		for (int j = 0; j < 3; j++) {
			if (gameBoard[j][i] != player) {
				win = false;
				break;
			} // exit
		} // for
		if (win) return true;
	} // for
	win = true;
    
    // win situation of NW-SE diagonal line
	for (int i = 0; i < 3; i++) {
		if (gameBoard[i][i] != player) {
			win = false;
			break;
		} // exit
	} // for
	if (win) return true;
	win = true;
    
    // win situation of NE-SW diagonal line
	for (int i = 0; i < 3; i++) {
		if (gameBoard[i][2 - i] != player) {
			win = false;
			break;
		} // exit
	} // for
	if (win) return true;
	return false;
} // hasWin

// check if the game is finished
bool ScoreBoard::checkFinish() {
	
    // true if gameboard is full
    for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameBoard[i][j] == NONE) {
				return false;
			} // exit
		} // for
	} // for
	inGame = false;
	return true;
} // checkFinish

// not in game
bool ScoreBoard::hasFinish() const {
	return !inGame;
} // hasFinish

// delete the scoreboard
void ScoreBoard::freeScoreBoard() {
	if (board) delete board;
	board = NULL;
} // freeScoreBoard

// get the game times
int ScoreBoard::getTimes() const {
	return times;
} // getTimes

// print the score of players
void ScoreBoard::printScore() const {
	cout << "Score is" << endl;
	cout << "X " << scores[X] << endl;
	cout << "O " << scores[O] << endl;
} // printScore
