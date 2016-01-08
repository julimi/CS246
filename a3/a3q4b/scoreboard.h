#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include "player.h"

class ScoreBoard {
    static int getRow(const std::string& pos);   // get the row of board
    static int getCol(const std::string& pos);   // get the column of board
    enum PlayerName gameBoard[3][3];             // the 3x3 gameboard
    ScoreBoard();                                // ctor
    ~ScoreBoard();                               // dtor
    static ScoreBoard* board;                    // scoreboard
    int scores[3];                               // array of score:0-none,1-X,2-O
    int times;                                   // game times
    bool inGame;                                 // determine if it is in game
    bool checkFinish();                          // check whether the game finishes
public:
    // show the process and result of the game
    void makeMove(enum PlayerName player, const std::string& pos, const bool& fromStdin);
    bool hasWin(enum PlayerName player) const;   // determine if someone wins
    bool hasFinish() const;                      // determine whether the game finishes
    static ScoreBoard* getScoreBoard();          // method to get the scoreboard
    void startNewGame();                         // start new game
    static void freeScoreBoard();                // delete the scoreboard
    // find out whether a given position is taken
    bool isOccupied(const std::string& pos) const;
    int getTimes() const;                        // method to get the game times
    void printScore() const;                     // print the score
};

#endif // SCOREBOARD_H
