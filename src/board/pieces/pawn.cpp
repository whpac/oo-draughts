#include "pawn.hpp"

PawnColor Pawn::getColor(){
    return this->color;
}

bool Pawn::isEmpty(Pawn& pawn) {
    return pawn.getColor() == PawnColor::no_pawn;
}

PawnColor Pawn::getOppositeColor(PawnColor color) {
    if(color == white) return black;
    if(color == black) return white;
    return no_pawn;
}