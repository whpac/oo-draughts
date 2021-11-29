#include "normal_pawn.hpp"
#include "king_pawn.hpp"

NormalPawn::NormalPawn(Board *board, PawnColor color) {
    this->board = board;
    this->color = color;
    this->type = normal;
}

bool NormalPawn::canBeMoved(Position from, Position to) {
    int d_row = to.getRow() - from.getRow();
    int d_col = to.getCol() - from.getCol();

    // Prevent from moves other than at angle 45 deg
    if(abs(d_row) != abs(d_col)) return false;

    // Ensure that the destination field is empty
    PawnPtr dest = this->board->getPawnAt(to);
    if(!Pawn::isEmpty(*dest)) return false;

    // On no account can a normal pawn travel more than two fields
    if(abs(d_row) > 2) return false;

    // Attempt to kill - kills can be performed backwards
    if(abs(d_row) == 2){
        Position middle(
                (from.getRow() + to.getRow()) / 2,
                (from.getCol() + to.getCol()) / 2
                );
        PawnPtr killed_pawn = this->board->getPawnAt(middle);

        // Can kill only opponent's pawns
        if(Pawn::isEmpty(*killed_pawn)) return false;
        if(killed_pawn->getColor() == this->color) return false;
        return true;
    }

    // Allow only forward moves
    if(d_row != 1 && this->color == PawnColor::white) return false;
    if(d_row != -1 && this->color == PawnColor::black) return false;

    return true;
}

PawnPtr NormalPawn::toPtr() {
    return make_shared<NormalPawn>(*this);
}

bool NormalPawn::canTransform(Position pos) {
    if(this->color == black && pos.getRow() == 0) return true;
    if(this->color == white && pos.getRow() == this->board->getSize() - 1) return true;
    return false;
}

PawnPtr NormalPawn::getTransform() {
    KingPawn king(this->board, this->color);
    return king.toPtr();
}

bool NormalPawn::canKill(Position pos) {
    int d_col[] = {-1, -1, 1, 1};
    int d_row[] = {-1, 1, -1, 1};

    // Check the four neighbour fields for pawns to kill
    for(int i = 0; i < 4; i++){
        // Neighbour must be of the opposite color
        PawnPtr neighbour = this->board->getPawnAt(
                Position(pos.getRow() + d_row[i], pos.getCol() + d_col[i]));
        if(!this->isOpposite(neighbour)) continue;

        // And there must be an empty space behind
        PawnPtr behind_neighbour = this->board->getPawnAt(
                Position(pos.getRow() + 2*d_row[i], pos.getCol() + 2*d_col[i]));
        if(Pawn::isEmpty(*behind_neighbour)) return true;
    }

    return false;
}
