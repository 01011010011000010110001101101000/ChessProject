#ifndef Bishop_hpp
#define Bishop_hpp

#include "Chess.hpp"
#include "Square.hpp"

class Bishop {
private:
    Square* location = nullptr;
public:
    char symbol;
    Bishop(char symbol, char file, int rank);
    bool isMoveLegal(char file, int rank);
    void move(char file, int rank);
    Square* const getLocation()const;
};


#endif /* Bishop_hpp */
