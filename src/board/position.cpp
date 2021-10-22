#include "position.hpp"

Position::Position(int row, int col){
    this->row = row;
    this->col = col;
}

int Position::getRow(){
    return this->row;
}

int Position::getCol(){
    return this->col;
}