#include "Position.h"

Position::Position(int passedX, int passedY){

        x = passedX;
        y = passedY;
}

Position::~Position(){}

bool operator<(const Position &lhs, const Position &rhs){

        //will result in [(0,0). (0,1), (0,2), (1,0), (2,0)] ordering
        // if((lhs.x <= rhs.x) && (lhs.y < rhs.y)){

        //        return true;
                
        // }

        // return false;

        
        // This is fine for a small number of members.
        // But I prefer the brute force approach when you start to get lots of members.
        return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));

}