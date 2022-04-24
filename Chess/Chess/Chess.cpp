#include "Chess.hpp"
#include <iostream>
#include <vector>
#define CHECKVECTOR(x)\
for (auto piece = x.begin(); piece != x.end(); piece++)\
{\
    if (piece->getLocation() == originSquare){\
        piece->move(newF, newR);\
        return;\
    }\
}

std::vector<Bishop> Bvector = {Bishop('B', 'c', 1 ), Bishop('B', 'f', 1)};
std::vector<Bishop> bvector = {Bishop('b', 'c', 8 ), Bishop('b', 'f', 8)};
std::vector<WhitePawn> Pvector = { WhitePawn('a', 2), WhitePawn('b', 2), WhitePawn('c', 2),
WhitePawn('d', 2), WhitePawn('e', 2), WhitePawn('f', 2), WhitePawn('g', 2), WhitePawn('h', 2) };
std::vector<BlackPawn> pvector = { BlackPawn('a', 7), BlackPawn('b', 7), BlackPawn('c', 7),
BlackPawn('d', 7), BlackPawn('e', 7), BlackPawn('f', 7), BlackPawn('g', 7), BlackPawn('h', 7) };
std::vector<Rook> Rvector = {Rook('R','a',1), Rook('R','h',1)};
std::vector<Rook> rvector = {Rook('r','a',8), Rook('r','h',8)};


void Chess::clearBoard()
{
    //clearBoard() without having created the board beforehand leads to print issues
    if (chessboard[0][0].getFile() != 'a')
        createBoard();
    for (int i = 0; i < 8; i++) //rank
    {
        for (int j = 0; j < 8; j++) //file
        {
            chessboard[i][j].setOccupant(chessboard[i][j].getColor());
        }
    }
}

void Chess::createBoard()
{
  // Generate all squares on chessboard
  for (int i = 0; i < 8; i++) //rank
  {
    for (int j = 0; j < 8; j++) //file
    {
        chessboard[i][j].setFile('a' + j);
        chessboard[i][j].setRank(1 + i);
        chessboard[i][j].setOccupant((chessboard[i][j].getOccupant()) ? :' ');
        chessboard[i][j].setColor((((i + j) % 2) == 0) ? ' ' : '*'); //"+" for white squares and " " for black squares for clean printing
    }
  }
}

void Chess::printBoard()
{

  const std::string WHITE_ROW_SPACER = " |** **     ** **     ** **     ** **     | ";
  const std::string BLACK_ROW_SPACER = " |     ** **     ** **     ** **     ** **| ";
  const std::string FILE_LABLES =    "    a    b    c    d    e    f    g    h    ";
  const std::string BORDER = "  =|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"; // fancy border design

  // Print file labels and gameboard border
  std::cout << FILE_LABLES << std::endl << BORDER << std::endl;
  // Print rows/ranks two at a time (since they alternate starting with black and white squares), higher ranks/rows on top
  for (int rank = 7; rank  >= 0; rank -= 2)
  {
    std::cout << WHITE_ROW_SPACER << std::endl;
    std::cout << rank + 1 << "|";
    // Print files/columns for row starting with white, two at a time (since they alternate between black and white squares)
    for (int file = 0; file < 8; file += 2)
    {
    
        std::cout << "* " << (chessboard[rank][file].isOccupied() ? chessboard[rank][file].getOccupant() : chessboard[rank][file].getColor()) << " *";
        // Print black square
        std::cout << "  " << (chessboard[rank][file + 1].isOccupied() ? chessboard[rank][file + 1].getOccupant() : chessboard[rank][file + 1].getColor()) << "  ";
    }
    std::cout << "|" << rank + 1 << std::endl << WHITE_ROW_SPACER << std::endl;

    std::cout << BLACK_ROW_SPACER << std::endl;
    std::cout << rank << "|";
    
    // Print files/columns for row starting with black, two at a time (since they alternate between black and white squares)
    for (int file = 0; file < 8; file += 2)
    {
        // Print black square
        std::cout << "  " << (chessboard[rank - 1][file].isOccupied() ? chessboard[rank - 1][file].getOccupant() : chessboard[rank - 1][file].getColor()) << "  ";
        // Print white square

        std::cout << "* " << (chessboard[rank - 1][file + 1].isOccupied() ? chessboard[rank - 1][file + 1].getOccupant() : chessboard[rank - 1][file + 1].getColor()) << " *";
    }
    std::cout << "|" << rank << std::endl << BLACK_ROW_SPACER << std::endl;
  }
  // Print bottom labels and border
  std::cout << BORDER << std::endl << FILE_LABLES << std::endl;
}


void Chess::makeMove(){
    std::string input = " ";
    int currentF, newF, currentR, newR;
    currentR = currentF = newF = newR = 0;
    while (input.length()<4){
        std::cin >> input;
        if (input.length()<4 //correct length check
            ||input[0] - 'a' < 0 || input[0] - 'a' > 7 || input[2] - 'a' < 0 || input[2] - 'a' > 7 // valid input check, which
            ||input[1] - '0' < 0 || input[1] - '0'  > 7 || input[3] - '0' < 0 || input[3] - '0'  > 7){
            //makes boundary checks for each piece a bit redundant, right?
            std::cout << "Invalid\n";
            input = " ";
        } else {
            currentF = input[0] - 'a';
            newF = input[2] - 'a';
            currentR = input[1] - '0';
            newR = input[3] - '0';
        }
    }
    
    Square* originSquare = &Chess::chessboard[currentF][currentR];
    
    CHECKVECTOR(Pvector)
    CHECKVECTOR(pvector) // pawns are most abundant which means they should be checked first.

    CHECKVECTOR(Bvector)
    CHECKVECTOR(bvector)
   // CHECKVECTOR(H) I'm guessing the symbol for the knight since 'k's are already taken.
   // CHECKVECTOR(h)
    CHECKVECTOR(Rvector)
    CHECKVECTOR(rvector)

}
