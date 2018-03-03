#include <iostream>
#include "Board.h"

using namespace std;

int main(void){


    //cout << "Ready" << endl;
    
    Board newboard(20);

    newboard.Insert(1, 2, 3);

    newboard.Insert(4, 2, 3);

    
    newboard.Insert(1, 2, 1);


    return 0;
}