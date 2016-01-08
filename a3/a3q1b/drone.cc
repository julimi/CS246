#include <iostream>
#include <string>
#include <cstdlib>
#include "drone.h"

using namespace std;

// constructor(ctor) of Drone
Drone::Drone() {
    count = 0;        // total unit of distance
    dir = 0;          // direction: 0(N), 1(E), 2(S), 3(W)
    cur.ew = 0;       // x-axis of current position
    cur.ns = 0;       // y=axis of current position
} // Drone

/* put the previous position to the array
 * after the unit of distance increases*/
void Drone::putcur() {
    pos[count++] = cur;
} // Drone::putcur

// make robot go forward by 1 unit
void Drone::forward() {
    
    /* run putcur() firstly 
     * because the robot gonna move*/
    putcur();

    // the change of current position
    cur.ew += step[dir][0];
    cur.ns += step[dir][1];
} // Drone::forward

// the robot go backward by 1 unit
void Drone::backward() {

    /* run putcur() firstly 
     * because the robot gonna move*/
    putcur();

    // the change of current position
    cur.ew -= step[dir][0];
    cur.ns -= step[dir][1];
} // Drone::backward

// the robot turns left
void Drone::left() {
    // turn left anticlockwise 90 degrees
    dir = (dir + 3) % 4;
} // Drone::left

// the robot turns right
void Drone::right() {
    // turn right clockwise 90 degrees
    dir = (dir + 1) % 4;
} // Drone::right

// give the current position
Position Drone::current() {
    return cur;
} // Drone::current

// give the total distance
int Drone::totalDistance() {
    return count;
} // Drone::totalDistance

// give the Manhattan Distance
int Drone::manhattanDistance() {
    return abs(cur.ew) + abs(cur.ns);
} // Drone::manhattanDistance

// determine the position repeated or not
bool Drone::repeated() {
    for (int i = 0; i < count; i++) {
        // repeated if we can the same position in the array
        if (cur.ew == pos[i].ew && cur.ns == pos[i].ns) return true;
    } // for
    return false;
} // Drone::repeated

/* the helper 2d array:
 * if robot faces to north, its change is step[0][0-1]:{0,1}
 * if robot faces to east, its change is step[1][0-1]:{1,0}
 * if robot faces to south, its change is step[2][0-1]:{0,-1}
 * if robot faces to west, its change is step[3][0-1]:{-1,0} */
const int Drone::step[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
}; // Drone::step[4][2]
