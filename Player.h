//guard code
#ifndef Player_h
#define Player_h
#include "Position.h"

class Player{

    public:
    //Constructor
    Player(int IDNumber, int passedXPos, int passedYPos);

    //Getter for ID
    int GetID();

    //Getter for position
    Position GetPosition() const;
    
    //Destructor
    ~Player();

    private:

    //ID
    int IDNumber;

    //Position
    Position playerPosition;

};
bool operator<(const Player &lhs, const Player &rhs);

#endif