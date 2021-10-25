#include "normal_pawn.hpp"

NormalPawn::NormalPawn(Board *board, PawnColor color) {
    this->board = board;
    this->color = color;
}

bool NormalPawn::canBeMoved(Position from, Position to) {
    int d_row = to.getRow() - from.getRow();
    int d_col = to.getCol() - from.getCol();

    // Prevent from moves other than at angle 45 deg
    if(abs(d_row) != abs(d_col)) return false;

    if(abs(d_row) > 1){
        // Attempt to kill
    }

    // Allow only forward moves
    if(d_row != 1 && this->color == white) return false;
    if(d_row != -1 && this->color == black) return false;

    return true;
}
