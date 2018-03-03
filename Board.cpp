
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

        //insert the ID + player into the list
        IDList.insert(pair<int, Player>(passedID, Player(passedID, passedX, passedY)));
       
        //insert position into the board map
        //1 for space occupied
        board.insert(pair<Position, int>(Position(passedX, passedY), 1));

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
    if(IDList.size() >= (xMax + 1)){

        cout << "Error: Maximum number of players reached. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;

    }

    //check to see if the passed ID already exists in the list
    //iterator used for find
    map<int, Player>::iterator mapIt = IDList.find(passedID); 


    if(mapIt != IDList.end()){
        
        cout << "Error: PlayerID already exists. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;
        
    }


    //check for empty space
    //utilize iterator for checking that the position is empty
    map<Position, int>::iterator boardMapIt = board.find(Position(passedX, passedY));;
    
    if(boardMapIt != board.end()){
        
        cout << "Error: Insertion location is not empty. Unable to insert new player" <<  endl;
        cin.get();
        system("clear");
        return false;
        
    }
    
    //all neccesary conditions passed
    return true;
}

bool Board::Find(int targetPlayerID){

    //use default stl::map find function
    map<int, Player>::iterator mapIt = this->IDList.find(targetPlayerID);


    if(mapIt != this->IDList.end()){

        return true;
    }
    
    //target not in ID set
    return false;


}

bool Board::Remove(int targetPlayerID){

    //check for playerID existence
    if(Find(targetPlayerID) == false){

        return false;

    }

    //target ID exists in the lists, so time to remove
    //set iterator to target ID
    map<int, Player>::iterator mapIt = IDList.find(targetPlayerID);

    //remove the player from its space on the board
    board.erase(mapIt->second.GetPosition());

    //remove the id + Player from the IDList
    IDList.erase(mapIt);

    return true;

}