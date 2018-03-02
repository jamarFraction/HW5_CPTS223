//guard code
#ifndef Board_h
#define Board_h

#include <iostream>
#include <map>
#include <set>
#include <stdlib.h>
#include "Player.h"

using namespace std;

class Board{

    public:
    //Constructor
    Board(int defaultSize = 0);

    //Destructor
    ~Board();

    //Insert
    bool Insert(int passedID, int passedX, int passedY);

    private:
    //Playing board
    map <Position, int> board;

    //X Bound
    int xMax;

    //Y Bound
    int yMax;

    //Player list
    set<Player> playerList;

    //ID List
    set<int> IDList;

    bool checkInsertionPreconditions(int passedID, int passedX, int passedY);
};

#endif