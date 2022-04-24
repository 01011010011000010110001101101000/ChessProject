#ifndef Square_hpp
#define Square_hpp

class Square {
    private:
        //data
        char file;
        char occupant;
        char color;
        int rank;
    public:
        //functions
        Square();
        Square(char file, int rank, char color);
        char getColor();
        char getFile();
        char getOccupant();
        int getRank();
        bool isOccupied();
        bool isOccupiedByBlack();
        bool isOccupiedByWhite();
        void setColor(char newCol);
        void setFile(char fileVal);
        void setOccupant(char newOcc);
        void setRank(int rankNum);
};

#endif /* Square_hpp */
