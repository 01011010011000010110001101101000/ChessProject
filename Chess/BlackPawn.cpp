#include "BlackPawn.hpp"
#include "Chess.hpp"
#define SqRANK location->getRank()
#define SqFILE location->getFile()
//
BlackPawn::BlackPawn(char newFile, int newRank) {
    isFirstMove = true;
    this->location = &Chess::chessboard[newRank-1][newFile-'a'];
    location->setOccupant(SYMBOL);
}

bool BlackPawn::isMoveLegal(char newFile, int newRank){
    
    // all legal conditions for movement
    if ((((newFile == SqFILE) //no side-to-side movement
        && ((newRank == SqRANK - 2 && isFirstMove)|| newRank == SqRANK - 1)// 2 is legal first move/ one is legal first move as well, but all subsequent moves must be one
        && (!Chess::chessboard[newRank-1][newFile - 'a'].isOccupied())) //enemy capture is not legal when movement is forward
        ||((newFile == SqFILE+1 || newFile == SqFILE-1) //if we see side-to-side movement
        && (newRank == SqRANK-1) // the rank must change,
        && (Chess::chessboard[newRank-1][newFile - 'a'].isOccupiedByWhite()))) // and an enemy must be present
        &&(newFile >= 'a' && newFile <= 'h' && newRank > 0 && newRank < 9)) //in any case, boundary must be checked
        return true;
    
    // Otherwise move is illegal
    return false;
}

void BlackPawn::move(char newFile, int newRank) {
    if (BlackPawn::isMoveLegal(newFile, newRank)){

        Chess::chessboard[SqRANK-1][SqFILE -'a'].setOccupant(Chess::chessboard[SqRANK-1][SqFILE - 'a'].getColor());
        Chess::chessboard[newRank-1][newFile - 'a'].setOccupant(this->SYMBOL);
        this->location = &Chess::chessboard[newRank-1][newFile - 'a'];
        isFirstMove = false;
    }
}

Square* const BlackPawn::getLocation()const{
    return this->location;
}

