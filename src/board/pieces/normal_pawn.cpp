#include "normal_pawn.hpp"

NormalPawn::NormalPawn(Board *board, PawnColor color) {
    this->board = board;
    this->color = color;
}

bool NormalPawn::canBeMoved(Position from, Position to) {
    return true;
}
