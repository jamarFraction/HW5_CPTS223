#include "Player.h"

Player::Player(int passedID, int passedXPosition, int passedYPosition){

    //set the class data members with the passed arguments
    this->IDNumber = passedID;
    this->playerPosition.x = passedXPosition;
    this->playerPosition.y = passedYPosition;

    
}

Player::~Player(){}

int Player::GetID(){

    return this->IDNumber;

}

Position Player::GetPosition() const{

    return this->playerPosition;
}

void Player::SetPosition(int passedX, int passedY){

    this->playerPosition.x = passedX;
    this->playerPosition.y = passedY;


}

bool operator<(const Player &lhs, const Player &rhs){

    //will result in 0, 1, 2, 3 ordering
    if(lhs.GetPosition().x < rhs.GetPosition().y){

        return true;
    }

    return false;
}
