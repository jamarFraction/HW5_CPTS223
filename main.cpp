#include <iostream>
#include "Board.h"

using namespace std;

int main(void){


    //cout << "Ready" << endl;
    
    Board newboard(20);

    newboard.Insert(1, 2, 3);

    newboard.Insert(4, 2, 4);

    newboard.Remove(1);

    newboard.Insert(1, 4, 7);

    newboard.Insert(3, 2, 4);

    cout << newboard.Find(2) << "\n" << newboard.Find(4) << endl;



    return 0;
}