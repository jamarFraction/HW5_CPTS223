#include "Player.h"

Player::Player(int passedID, int passedXPosition, int passedYPosition){

    //set the class data members with the passed arguments
    this->IDNumber = passedID;
    this->playerPosition.x = passedXPosition;
    this->playerPosition.y = passedYPosition;

    
}

Player::~Player(){}