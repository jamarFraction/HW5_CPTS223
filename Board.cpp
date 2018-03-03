
#include "Board.h"

Board::Board(int passedSize){

    //set the private bounds, zero-based indexing used
    this->xMax = passedSize - 1;
    this->yMax = passedSize - 1;

}

Board::~Board(){}

bool Board::Insert(int passedID, int passedX, int passedY){

    //check preconditions for insertion
    if(checkInsertionPreconditions(passedID, passedX, passedY) == true){

        //create new player
        Player newPlayer(passedID, passedX, passedY);

        //add player to the player list
        playerList.insert(newPlayer);

        //add the Player's ID to the ID list
        IDList.insert(newPlayer.GetID()); 

        //insert position into the board map
        board.insert(pair<Position, int>(newPlayer.GetPosition(), 1));

        return true; 

    }

    return false;

}


bool Board::checkInsertionPreconditions(int passedID, int passedX, int passedY){

    //Conditions for insertion:
    //No duplicate playerIDs
    //Players n cannot exceed max board bound
    //Board space for insertion should be empty
    //function returns true if all preconditions for insertion are met, false otherwise 

    //check for the number of players exceeding M
    if(playerList.size() >= (xMax + 1)){

        cout << "Error: Maximum number of players reached. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;

    }

    //check to see if the passed ID already exists
    //iterator used for find
    set<int>::iterator setIt = IDList.find(passedID);


    if(setIt != IDList.end()){
        
        cout << "Error: PlayerID already exists. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;
        
    }

    //check for empty space
    //create a temporary position with the passed location info
    Position tempPosition(passedX, passedY);

    //utilize iterator for checking that the position is empty
    map<Position, int>::iterator mapIt;
    
    mapIt = board.find(tempPosition);
    
    if(mapIt != board.end()){
        
        cout << "Error: Insertion location is not empty. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;
        
    }
    
    //all neccesary conditions passed
    return true;
}