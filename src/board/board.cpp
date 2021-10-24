#include "board.hpp"

Board::Board(int size){
    this->boardSize = size;

    for(int i = 0; i < size * size; i++){
        this->board.push_back(make_shared<Pawn>(Pawn(this, no_pawn)));
    }
}


int Board::getSize() const{
    return this->boardSize;
}


shared_ptr<Pawn> Board::getPawnAt(Position pos){
    if(!this->isPositionWithinBounds(pos)){
        return make_shared<Pawn>(this, no_pawn);
    }

    int idx = this->positionToIndex(pos);
    return (this->board[idx]);
}


void Board::setPawnAt(Position pos, shared_ptr<Pawn> pawn){
    if(!this->isPositionWithinBounds(pos)) return;

    int idx = this->positionToIndex(pos);
    this->board[idx] = move(pawn);
}

bool Board::movePawn(Position from, Position to) {
    shared_ptr<Pawn> pawn = this->getPawnAt(from);
    if(pawn->getColor() == no_pawn) return false;

    this->setPawnAt(to, pawn);
    this->setPawnAt(from, make_shared<Pawn>(this, no_pawn));
    return true;
}


int Board::positionToIndex(Position pos) const{
    return pos.getCol() * this->boardSize + pos.getRow();
}


bool Board::isPositionWithinBounds(Position pos) const{
    if(pos.getCol() < 0) return false;
    if(pos.getRow() < 0) return false;
    if(pos.getCol() >= this->boardSize) return false;
    if(pos.getRow() >= this->boardSize) return false;

    return true;
}

bool Board::isPlayableField(Position pos) {
    return this->isPositionWithinBounds(pos);
}