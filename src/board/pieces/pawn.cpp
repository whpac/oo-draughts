#include "pawn.hpp"

PawnColor Pawn::getColor(){
    return this->color;
}

bool Pawn::isEmpty(Pawn& pawn) {
    return pawn.getColor() == PawnColor::no_pawn;
}

bool Pawn::isOpposite(PawnPtr pawn) {
    PawnColor opposite = Pawn::getOppositeColor(this->color);
    return opposite == pawn->getColor();
}

PawnColor Pawn::getOppositeColor(PawnColor color) {
    if(color == white) return black;
    if(color == black) return white;
    return no_pawn;
}