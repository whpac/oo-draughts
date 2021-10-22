#include "board.hpp"
#include<functional>

Board::Board(int size){
    this->boardSize = size;

    for(int i = 0; i < size; i++){
        this->board.push_back(new Pawn(this, no_pawn));
    }
}


int Board::getSize(){
    return this->boardSize;
}


Pawn& Board::getPawnAt(Position pos){
    if(!this->isPositionWithinBounds(pos)){
        Pawn p(this, no_pawn);
        return p;
    }

    int idx = this->positionToIndex(pos);
    return *(this->board[idx]);
}


void Board::setPawnAt(Position pos, Pawn& pawn){
    if(!this->isPositionWithinBounds(pos)) return;

    int idx = this->positionToIndex(pos);
    this->board[idx] = &pawn;
}


int Board::positionToIndex(Position pos){
    return pos.getCol() * this->boardSize + pos.getRow();
}


bool Board::isPositionWithinBounds(Position pos){
    if(pos.getCol() < 0) return false;
    if(pos.getRow() < 0) return false;
    if(pos.getCol() >= this->boardSize) return false;
    if(pos.getRow() >= this->boardSize) return false;

    return true;
}