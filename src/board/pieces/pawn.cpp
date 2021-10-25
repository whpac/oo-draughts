#include "pawn.hpp"

PawnColor Pawn::getColor(){
    return this->color;
}

bool Pawn::isEmpty(Pawn& pawn) {
    return pawn.getColor() == PawnColor::no_pawn;
}