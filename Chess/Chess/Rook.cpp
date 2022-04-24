#include "Rook.hpp"
#include "Chess.hpp"
#include "Square.hpp"
#include <cctype>

#define SQ Chess::chessboard[newrank - 1][newfile - 'a']
#define thisRank location->getRank()
#define thisFile location->getFile()

Rook::Rook(char newSymbol, char newFile, int newRank) {
    this->symbol = newSymbol;
    this->location = &Chess::chessboard[newRank - 1][newFile - 'a'];
    location->setOccupant(symbol);
}

bool Rook::isMoveLegal(char newfile, int newrank) {

    // all legal movement conditions
    if (((!SQ.isOccupied() // Square may be unoccupied
        || ((location->isOccupiedByWhite() && SQ.isOccupiedByBlack())) // checks if other occupant is an enemy
        || (location->isOccupiedByBlack() && (SQ.isOccupiedByWhite())))) // ''
        &&((newfile >= 'a') && (newfile <= 'h') && (newrank > 0) && (newrank < 9)// checks boundary
        && !(newrank != thisRank && newfile != thisFile))){ // ensures movement is in only one direction

        //the difference between start sq and desired sq coordinates
        int diff = (newfile != thisFile) ? newfile - thisFile : newrank - thisRank;

        //the diff might be positive or negative.
        for (int i = (diff>0)? 1:-1; i != diff; (i<diff)?i++:i--){

            //the difference might be in rank or file
            if (newfile != thisFile){
                //if the file is where the diff is, then we iterate through squares along the file
                if (Chess::chessboard[thisRank-1][thisFile-'a'+i].isOccupied())
                    return false;
            } else {
                //otherwise, we look at squares along the rank
                if (Chess::chessboard[thisRank-1+i][thisFile-'a'].isOccupied())
                    return false;
            }
        }
        // if the function makes it to this point, we have not encountered a fail condition
        return true;
    } else {
        // if the function makes it to this point, we have encountered a fail condition
        return false;
    }
}

void Rook::move(char newFile, int newRank) {
    if (Rook::isMoveLegal(newFile, newRank)) {// move must be legal
        //change previous square obj occupant back to color: ' ' || '*'
        Chess::chessboard[thisRank - 1][thisFile - 'a'].setOccupant(Chess::chessboard[thisRank - 1][thisFile - 'a'].getColor());
        //change new square obj occupant to this->symbol: ('k' || 'K')
        Chess::chessboard[newRank - 1][newFile - 'a'].setOccupant(symbol);
        //change location to new square obj address
        this->location = &Chess::chessboard[newRank - 1][newFile - 'a'];
        }
}

Square* const Rook::getLocation() const{
    return this->location;
}






