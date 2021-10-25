#include "position.hpp"

Position::Position() {
    this->row = -1;
    this->col = -1;
}

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