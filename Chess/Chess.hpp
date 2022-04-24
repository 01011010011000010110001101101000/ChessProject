#ifndef Chess_hpp
#define Chess_hpp

#include "Bishop.hpp"
#include "BlackPawn.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Square.hpp"
#include "WhitePawn.hpp"
#include <vector>
//forward declarations
class Bishop;
class BlackPawn;
class WhitePawn;
class Rook;
class King;

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
    //template<typename T = WhitePawn>
    inline static std::vector<WhitePawn> Pvector;
    //template<typename T>
    inline static std::vector<BlackPawn> pvector;
    //template<typename T>
    inline static std::vector<Bishop> Bvector;
    //template<typename T>
    inline static std::vector<Bishop> bvector;
    //template<typename T>
    inline static std::vector<Rook> Rvector;
    //template<typename T>
    inline static std::vector<Rook> rvector;
    //template<typename T>
    inline static std::vector<King> Kvector;
};
#endif /* Chess_hpp */
