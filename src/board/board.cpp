#include "board.hpp"
#include "pieces/empty_field.hpp"

Board::Board(int size){
    this->boardSize = size;

    for(int i = 0; i < size * size; i++){
        PawnPtr p = EmptyField::makePtr(true);
        this->board.push_back(p);
    }
}


int Board::getSize() const{
    return this->boardSize;
}


PawnPtr Board::getPawnAt(Position pos){
    if(!this->isPositionWithinBounds(pos)){
        return EmptyField::makePtr(false);
    }

    int idx = this->positionToIndex(pos);
    return (this->board[idx]);
}


void Board::setPawnAt(Position pos, PawnPtr pawn){
    if(!this->isPositionWithinBounds(pos)) return;

    int idx = this->positionToIndex(pos);
    this->board[idx] = move(pawn);
}


bool Board::movePawn(Position from, Position to) {
    // Moved pawn must be of the appropriate color
    PawnPtr pawn = this->getPawnAt(from);
    if(pawn->getColor() != this->nextPlayer) return false;

    // Source field must contain a pawn and destination must be playable
    if(Pawn::isEmpty(*pawn)) return false;
    if(!this->isPlayableField(to)) return false;

    // The move must also be valid for this type of pawn
    if(!pawn->canBeMoved(from, to)) return false;

    // Check for possible transforms. If available, change the pawn
    if(pawn->canTransform(to)){
        PawnPtr new_pawn = pawn->getTransform();
        this->setPawnAt(to, new_pawn);
    }else{
        this->setPawnAt(to, pawn);
    }
    this->setPawnAt(from, EmptyField::makePtr(true));

    // Now it's the opponent's turn
    this->nextPlayer = Pawn::getOppositeColor(pawn->getColor());

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


int Board::countPawnsOfColor(PawnColor color) {
    int count = 0;
    for(int row = 0; row < this->boardSize; row++){
        for(int col = 0; col < this->boardSize; col++){
            PawnPtr pawn = this->getPawnAt(Position(row, col));
            if(pawn->getColor() == color) count++;
        }
    }
    return count;
}

PawnColor Board::getNextPlayer() {
    return this->nextPlayer;
}