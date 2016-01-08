#ifndef a3q1b_drone_h
#define a3q1b_drone_h

struct Position {
    int ew, ns;
};

struct Drone {
    Drone();
    void forward();
    void backward();
    void left();
    void right();
    Position current();
    int totalDistance();
    int manhattanDistance();
    bool repeated();
private:    
    int dir;
    Position pos[60];
    int count;
    static const int step[4][2];
    Position cur;
    void putcur();
};

#endif
