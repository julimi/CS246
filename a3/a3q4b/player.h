#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

enum PlayerName {
    NONE = 0, // none value in enum
    X, // 1
    O, // 2
};

class ScoreBoard;

class Player {
	static int playerCounts;     // count the number of plays
	ScoreBoard* board;           // the unique scoreboard
	std::istream& in;            // input
	bool fromStdin;              // determine if input from stdin
	Player(std::istream&, const PlayerName&, const bool&);  // copy ctor
	PlayerName name;             // Playername
public:
    // change player to string
	static std::string playerToStr(enum PlayerName player);
    // get player and its input
	static Player* getPlayer(std::istream& input, const PlayerName& name, const bool& fromStdin);
	void makeMove();             // move game
	~Player();                   // dtor
};

#endif // PLAYER_H
