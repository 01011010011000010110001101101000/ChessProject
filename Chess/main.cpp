class Bishop;
class BlackPawn;
class WhitePawn;
class Rook;
class King;
#include "Bishop.hpp"
#include "BlackPawn.hpp"
#include "Chess.hpp"
#include "TestCode.hpp"
#include "Square.hpp"
#include "Rook.hpp"
#include "WhitePawn.hpp"
#include <iostream>

int main()
{
    Chess::createBoard();
    Chess::printBoard();
    system("pause");

}



