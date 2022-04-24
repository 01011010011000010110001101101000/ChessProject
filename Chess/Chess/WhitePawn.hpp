#ifndef WhitePawn_hpp
#define WhitePawn_hpp

#include "Square.hpp"
#include "Chess.hpp"
#include "BlackPawn.hpp"

class WhitePawn {
private:
    //data
    Square* location = nullptr;
    bool isFirstMove;
public:
    const static char SYMBOL = 'P';
    WhitePawn(char newFile, int newRank);
    bool isMoveLegal(char newFile, int newRank);
    void move(char newFile, int newRank);
    Square* const getLocation()const;

};

#endif /* WhitePawn_hpp */
