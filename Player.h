//guard code
#ifndef Player_h
#define Player_h
#include "Position.h"

class Player{

    public:
    //Constructor
    Player(int IDNumber, int passedXPos, int passedYPos);
    

    //Destructor
    ~Player();

    private:

    //ID
    int IDNumber;

    //Position
    Position playerPosition;

};
#endif