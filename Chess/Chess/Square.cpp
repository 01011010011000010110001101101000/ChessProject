#include "Square.hpp"

Square::Square() = default;

Square::Square(char File, int Rank, char Color){
    file = (File >= 'a' && File <= 'h') ? File : file;
    rank = (Rank >= 1 && Rank <= 8) ? Rank : rank;
    color = (Color == ' '||Color == '*') ? Color : color;
}

char Square::getColor(){
    return color;
}

char Square::getFile(){
    return file;
}

char Square::getOccupant(){
    return occupant;
}

int Square::getRank(){
    return rank;
}

bool Square::isOccupied(){
    return (isOccupiedByWhite() || isOccupiedByBlack()) ? true : false;
}

bool Square::isOccupiedByBlack(){
    return (occupant >= 'a' && occupant <= 'z') ? true : false;
}

bool Square::isOccupiedByWhite(){
    return (occupant >= 'A' && occupant <= 'Z') ? true : false;
}

void Square::setColor(char newCol){
    color = (newCol == ' '||newCol == '*') ? newCol : color;
}

void Square::setFile(char fileVal){
    file = (fileVal >= 'a' && fileVal <= 'h') ? fileVal : file;
}

void Square::setOccupant(char newOcc){
    occupant = ((newOcc >= 'A' && newOcc <= 'Z') || (newOcc >= 'a' && newOcc <= 'z')) ? newOcc : color;
}

void Square::setRank(int newRank){
    rank = (newRank > 0 && newRank <= 8) ? newRank : rank;
}
