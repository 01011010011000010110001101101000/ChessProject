#include "Bishop.hpp"
#include "Chess.hpp"

#define SQR Chess::chessboard[newRank - 1][newFile - 'a']
#define CurrentRank location->getRank()
#define CurrentFile location->getFile()

Bishop::Bishop(char newSymbol, char newFile, int newRank) {
    this->symbol = newSymbol;
    this->location = &Chess::chessboard[newRank - 1][newFile - 'a'];
    location->setOccupant(symbol);
}

bool Bishop::isMoveLegal(char newFile, int newRank) {
    int diffFile = newFile - CurrentFile;
    int diffRank = newRank - CurrentRank;
    if ((diffFile*diffFile) == (diffRank*diffRank) // Squared differences are only identical if the movement is diagonal.
        && (newFile >= 'a' && newFile <= 'h' && newRank > 0 && newRank < 9) // boundary
        && (!SQR.isOccupied() || (location->isOccupiedByWhite() && SQR.isOccupiedByBlack()) // Square occupancy check
        || (location->isOccupiedByBlack() && SQR.isOccupiedByWhite()))) {

        // movement direction determination
        int i = (diffRank > 0) ? 1 : -1;
        int j = (diffFile > 0) ? 1 : -1;
        
        // for loop that accommodates all possible movement directions
        for (;i != diffRank;
            (i < diffRank) ? i++ : i--,
            (j < diffFile) ? j++ : j--) {
             //checking squares between current sq and desired sq
            if (Chess::chessboard[CurrentRank - 1 + i][CurrentFile - 'a' + j].isOccupied())
                return false;

        }
        // no fail conditions encountered
        return true;
    }

    return false;
}

void Bishop::move(char newFile, int newRank) {
    if (Bishop::isMoveLegal(newFile, newRank)) {// move must be legal
        //change previous square obj occupant back to color: ' ' || '*'
        Chess::chessboard[CurrentRank - 1][CurrentFile - 'a'].setOccupant(Chess::chessboard[CurrentRank - 1][CurrentFile - 'a'].getColor());
        //change new square obj occupant to this->symbol: ('k' || 'K')
        SQR.setOccupant(symbol);
        //change location to new square obj address
        this->location = &SQR;
    }
}

Square* const Bishop::getLocation()const{
    return this->location;
}
