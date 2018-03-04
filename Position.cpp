#include "Position.h"

Position::Position(int passedX, int passedY){

        x = passedX;
        y = passedY;
}

Position::~Position(){}

void Position::SetPosition(int passedX, int passedY){

        this->x = passedX;
        this->y = passedY;

}

bool operator<(const Position &lhs, const Position &rhs){

        //will result in [(0,0). (0,1), (0,2), (1,0), (2,0)] ordering
        return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));

}