#include "position.hpp"

Position::Position() {
    this->row = -1;
    this->col = -1;
}

Position::Position(int row, int col){
    this->row = row;
    this->col = col;
}

int Position::getRow() const{
    return this->row;
}

int Position::getCol() const{
    return this->col;
}

bool Position::operator==(Position p) const {
    return this->row == p.row && this->col == p.col;
}

bool Position::operator!=(Position p) const {
    return this->row != p.row || this->col != p.col;
}