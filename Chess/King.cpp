#include "King.hpp"
#include "Chess.hpp"
#include "Square.hpp"
#include <cctype>
//this is a macro, its sort of like an include, it just copy pastes what you want, where you want (use sparringly. it is here to make the logic easier to follow)
#define SQ Chess::chessboard[newRank - 1][newFile - 'a']
#define currentRank location->getRank()
#define currentFile location->getFile()

King::King(char newSymbol, char newFile, int newRank) {
    this->symbol = newSymbol;
    //assign address to location*
    this->location = &Chess::chessboard[newRank - 1][newFile - 'a'];
    // set square obj occupant
    location->setOccupant(symbol);
}

bool King::isMoveLegal(char newFile, int newRank) {
    
    // Move one square in all directions/capture enemy
    if ((((newRank-1 == currentRank || newRank+1 == currentRank || newRank == currentRank) // Checks if move is in King's radius of one
        && (newFile-1 == currentFile || newFile+1 == currentFile || newFile == currentFile) //''
        && ((!SQ.isOccupied()) || ((location->isOccupiedByWhite() && SQ.isOccupiedByBlack())) // Desired square may be unoccupied or be occupied by an enemy
        || (location->isOccupiedByBlack() && SQ.isOccupiedByWhite()))))// ''
        &&(newFile >= 'a' && newFile <= 'h' && newRank > 0 && newRank < 9)) // checks boundary
        return true;
    
    //otherwise illegal
    return false;
}

void King::move(char newFile, int newRank) {
    if (King::isMoveLegal(newFile, newRank)){// move must be legal
        //change previous square obj occupant back to color: ' ' || '*'
        Chess::chessboard[currentRank-1][currentFile-'a'].setOccupant(Chess::chessboard[currentRank-1][currentFile - 'a'].getColor());
        //change new square obj occupant to this->symbol: ('k' || 'K')
        SQ.setOccupant(symbol);
        //chang location to new square obj address
        this->location = &SQ;
    }
}
Square* const King::getLocation()const{
    return this->location;
}
