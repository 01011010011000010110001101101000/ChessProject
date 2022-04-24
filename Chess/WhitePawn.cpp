#include "WhitePawn.hpp"
#include "Chess.hpp"
#define RAANK location->getRank()
#define FIILE location->getFile()

WhitePawn::WhitePawn(char newFile, int newRank) {
    isFirstMove = true;
    this->location = &Chess::chessboard[newRank-1][newFile-'a'];
    location->setOccupant(this->SYMBOL);

}

bool WhitePawn::isMoveLegal(char newFile, int newRank){

    // all legal conditions
    if ((((newFile == FIILE) //no side-to-side movement
        && ((newRank-2 == RAANK && isFirstMove)|| newRank-1 == RAANK)// 2 is legal first move/ one is legal first move as well, but all subsequent moves must be one
        && (!Chess::chessboard[newRank-1][newFile - 'a'].isOccupied()))//enemy capture is not legal when movement is forward
        ||((newFile == FIILE+1 || newFile == FIILE-1)//if we see side-to-side movement
        && (newRank-1 == RAANK) // the rank must change,
        && Chess::chessboard[newRank-1][newFile - 'a'].isOccupiedByBlack()))// and an enemy must be present
        && (newFile >= 'a' && newFile <= 'h' && newRank > 0 && newRank < 9))//in any case, boundary must be checked
        return true;

    // Otherwise move is illegal
    return false;
}

void WhitePawn::move(char newFile, int newRank) {
    if (WhitePawn::isMoveLegal(newFile, newRank)){
        Chess::chessboard[RAANK-1][FIILE -'a'].setOccupant(Chess::chessboard[RAANK-1][FIILE - 'a'].getColor());
        Chess::chessboard[newRank-1][newFile - 'a'].setOccupant(this->SYMBOL);
        this->location = &Chess::chessboard[newRank-1][newFile - 'a'];
        isFirstMove = false;
    }
}

Square* const WhitePawn::getLocation()const{
    return this->location;
}
