
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
        board.insert(pair<Position, int>(Position(passedX, passedY), passedID));

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

        cout << "Error: Maximum number of players reached. Unable to insert new player ID: " <<
        passedID <<". Press enter.." <<  endl;
        cin.get();
        system("clear");
        return false;

    }

    //check to see if the passed ID already exists in the list
    //iterator used for find
    map<int, Player>::iterator mapIt = IDList.find(passedID); 


    if(mapIt != IDList.end()){
        
        cout << "Error: PlayerID: " << passedID <<" already exists. Unable to insert new player. Press enter.." <<  endl;
        cin.get();
        system("clear");
        return false;
        
    }


    //check for empty space
    //utilize iterator for checking that the position is empty
    map<Position, int>::iterator boardMapIt = board.find(Position(passedX, passedY));;
    
    if(boardMapIt != board.end()){
        
        cout << "Error: Insertion location (" << passedX <<
        ", " << passedY << ") is not empty. Unable to insert new player. Press enter.." <<  endl;
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

void Board::PrintByID(){

    //check if the board is empty before proceeding
    if(this->IDList.size() == 0){

        cout << "Error: The board is empty. Press enter.." << endl;
        cin.get();
        system("clear");
    }else{

        //iterate through the IDList, printing ID, followed by position
        //ex: ID Number: i. Position: x, y 
        map<int, Player>::iterator mapIt = IDList.begin();

        while(mapIt != IDList.end()){

            cout << "ID Number: " << mapIt->first << ". Position: " << mapIt->second.GetPosition().x <<
                ", " << mapIt->second.GetPosition().y << endl;

            ++mapIt;
        }

        cout << "Press enter..";
        cin.get();
        system("clear");
    }

    


}

bool Board::MoveTo(int playerID, int xDestination, int yDestination){

    if(checkRemovalPreconditions(playerID, xDestination, yDestination) == true){

        //create an iterator and
        //check if the position is already occupied
        map<Position, int>::iterator boardIt = board.find(Position(xDestination, yDestination));

        if(boardIt != board.end()){

            cout << "Player ID: " << boardIt->second << " is being removed. Press enter.." << endl;
            cin.get();
            system("clear");

            //process removal
            this->Remove(boardIt->second);
        }

        //IDIterator for updating position in IDList
        map<int, Player>::iterator IDIt = IDList.find(playerID);

        //Set board iterator to the target player on the board
        boardIt = board.find(IDIt->second.GetPosition());

        //remove the moving player from the board
        board.erase(boardIt);

        //add it back to the board with new position
        board.insert(pair<Position, int>(Position(xDestination, yDestination), playerID));

        //update location in IDList
        IDIt->second.SetPosition(xDestination, yDestination);
        
        return true;
    }

    return false;
    

}

bool Board::checkRemovalPreconditions(int passedID, int passedX, int passedY){


    //check for ID pre-existence
    if(this->Find(passedID) == false){

        cout << "Error: PlayerID: " << passedID << " not found. Press enter..";
        cin.get();
        system("clear");
        return false;

    }

    //Iterator
    map<int, Player>::iterator mapIt = IDList.find(passedID);

    //check move validaity
    //is move within bounds?
    if(passedX < 0 || passedY < 0 || passedX > xMax || passedY > yMax){

            cout << "Error: Position: (" << passedX << ", " << passedY <<
                ") is out of bounds. Press enter..";
            cin.get();
            system("clear");
            return false;

        }

    //is the move within the restricted location set? (horizontal, vertical, or any diagonal)
    if((abs(mapIt->second.GetPosition().x - passedX) !=
        abs(mapIt->second.GetPosition().y - passedY)) && (mapIt->second.GetPosition().x  != passedX) &&
        (mapIt->second.GetPosition().y != passedY)){ 

            cout << "Error: Position: (" << passedX << ", " << passedY <<
                ") is not within the permitted move set (horizontal, vertical, or any diagonal). Press enter..";
            cin.get();
            system("clear");
            return false;

    }

    //all preconditions met
    return true;

}