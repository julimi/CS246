#include "player.h"
#include "scoreboard.h"

using namespace std;

int Player::playerCounts = 0;

Player::Player(std::istream& input, const PlayerName& name, const bool& fromStdin)
		: in(input), name(name), fromStdin(fromStdin) {
	playerCounts++;
	board = ScoreBoard::getScoreBoard();
} // ctor

Player::~Player() {
	playerCounts--;
} // dtor

// get player and its input
Player* Player::getPlayer(std::istream& input, const PlayerName& name, const bool& fromStdin) {
	if (playerCounts >= 2) {
		throw -1;   // solve the fault situation
	} // exit
	return new Player(input, name, fromStdin);
} // getPlayer

// give each move output
void Player::makeMove() {
	cout << playerToStr(name) << "'s move" << endl;
	string move;
    
    // input the move
	do {
		in >> move;
	} while(board->isOccupied(move));  // while
	
    // use the given move to show the process and result
    board->makeMove(name, move, fromStdin);
} // makeMove

string Player::playerToStr(enum PlayerName player) {
	switch (player) {
		case NONE:
			return "NONE";
		case X:
			return "X";
		case O:
			return "O";
		default:
			throw -1;
	} // switch
} // playerToStr
