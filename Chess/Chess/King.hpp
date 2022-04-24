#ifndef King_hpp
#define King_hpp

#include "Square.hpp"

class King
{
    private:
        // data
        Square* location = nullptr;
    public:
        char symbol;
        // functions
        King(char symbol, char file, int rank);
        bool isMoveLegal(char file, int rank);
        void move(char file, int rank);
        Square* const getLocation()const;
};

#endif /* King_hpp */
