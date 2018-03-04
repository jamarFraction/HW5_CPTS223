//guard code
#ifndef Player_h
#define Player_h
#include "Position.h"

class Player{

    public:
    //Constructor
    Player(int IDNumber = -1, int passedXPos = -1, int passedYPos = -1);

    //Getter for ID
    int GetID();

    //Getter for position
    Position GetPosition() const;

    void SetPosition(int passedX, int passedY);
    
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