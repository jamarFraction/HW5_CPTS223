//guard code
#ifndef Position_h
#define Position_h
class Position{


    public:
    
    Position(int passedX = 0, int passedY = 0);

    ~Position();

    int x;
    int y;

};

//overloaded operator needed for class use as map key
bool operator<(const Position &lhs, const Position &rhs);

#endif