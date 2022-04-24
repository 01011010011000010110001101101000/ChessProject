#ifndef Rook_hpp
#define Rook_hpp
#include "Square.hpp"

class Rook {

private:
    
    Square* location = nullptr;
    

public:

    char symbol;
    Rook(char symbol, char file, int rank);
    bool isMoveLegal(char file, int rank);
    void move(char file, int rank);
    Square* const getLocation()const;

};
#endif /* Rook_hpp */
