#ifndef BlackPawn_hpp
#define BlackPawn_hpp

#include "Square.hpp"
#include "Chess.hpp"
#include "WhitePawn.hpp"
//
class BlackPawn {
private:
    //data
    Square* location = nullptr;
    bool isFirstMove;
public:
    const static char SYMBOL = 'p';
    BlackPawn(char newFile, int newRank) ;
    bool isMoveLegal(char newFile, int newRank);
    void move(char newFile, int newRank);
    Square* const getLocation()const;

};

#endif /* BlackPawn_hpp */
