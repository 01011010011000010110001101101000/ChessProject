#include "BlackPawn.hpp"
#include "Chess.hpp"
#include "TestCode.hpp"
#include "WhitePawn.hpp"
#include <iostream>

void TestCode::testPawns()
{
    // Create a chessboard
    Chess::clearBoard();

    // Test print board
    std::cout << "Testing print empty board:" << std::endl;
    Chess::printBoard();

    // Test creating pawns
    std::cout << "Testing creating pawns:" << std::endl;
    WhitePawn P1('a', 2);
    WhitePawn P2('b', 2);
    WhitePawn P3('c', 2);
    WhitePawn P4('d', 2);
    WhitePawn P5('e', 2);
    WhitePawn P6('f', 2);
    WhitePawn P7('g', 2);
    WhitePawn P8('h', 2);
    BlackPawn p1('a', 7);
    BlackPawn p2('b', 7);
    BlackPawn p3('c', 7);
    BlackPawn p4('d', 7);
    BlackPawn p5('e', 7);
    BlackPawn p6('f', 7);
    BlackPawn p7('g', 7);
    BlackPawn p8('h', 7);
    Chess::printBoard();

    // Test move forward 2
    std::cout << "Testing moving forward 2:" << std::endl;
    P1.move('a', 4);
    p1.move('a', 5);
    P2.move('b', 4);
    p2.move('b', 5);
    Chess::printBoard();

    // Test capturing opponent pawn
    std::cout << "Testing capturing opponent pawn:" << std::endl;
    P1.move('b', 5);
    p1.move('b', 4);
    Chess::printBoard();

    // Test move forward 1
    std::cout << "Testing move forward 1:" << std::endl;
    P1.move('b', 6);
    p1.move('b', 3);
    Chess::printBoard();

    // Test move forward two after first move
    std::cout << "Testing move forward 2 after first try (should see no move):" << std::endl;
    P1.move('b', 8);
    p1.move('b', 1);
    Chess::printBoard();

    // Test move forward more than two
    std::cout << "Testing move forward more than two (should see no move):" << std::endl;
    P3.move('c', 5);
    p4.move('d', 4);
    Chess::printBoard();

    // Test move backward
    std::cout << "Testing moving backward(should see no move):" << std::endl;
    P1.move('b', 5);
    p2.move('b', 2);
    Chess::printBoard();

    // Test moving left or right
    std::cout << "Testing moving left or right (should see no move):" << std::endl;
    P1.move('a', 6);
    p2.move('c', 3);
    Chess::printBoard();

    // Test moving past end of board
    std::cout << "Testing moving past end of board (shoud stop at rank 8 and rank 1):" << std::endl;
    P1.move('b', 7);
    P1.move('b', 8);
    P1.move('b', 9);
    p1.move('b', 2);
    p1.move('b', 1);
    p1.move('b', 0);
    Chess::printBoard();
}



