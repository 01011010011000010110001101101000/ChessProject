#ifndef Chess_hpp
#define Chess_hpp

#include "Bishop.hpp"
#include "BlackPawn.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Square.hpp"
#include "WhitePawn.hpp"
#include <vector>


//
class Chess
{
  public:
  
  // Data fields
    inline static Square chessboard[8][8]; // chessboard[rank][file]

  // Functions
  static void clearBoard();
  static void createBoard();
  static void printBoard();
  static void makeMove();
    
private:
    template<typename T>
    inline static std::vector<T> Pvector;
    template<typename T>
    inline static std::vector<T> pvector;
    template<typename T>
    inline static std::vector<T> Bvector;
    template<typename T>
    inline static std::vector<T> bvector;
    inline static std::vector<Rook> Rvector = {Rook('R','a',1), Rook('R','h',1)};
    inline static std::vector<Rook> rvector = {Rook('r','a',8), Rook('r','h',8)};
    inline static std::vector<King> Kvector = { King('K','e',1)};
    inline static std::vector<King> kvector = { King('k','e',8)};
};
#endif /* Chess_hpp */
