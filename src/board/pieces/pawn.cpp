#include "pawn.hpp"

Pawn::Pawn(Board* board, PawnColor color){
    this->board = board;
    this->color = color;
}

PawnColor Pawn::getColor(){
    return this->color;
}