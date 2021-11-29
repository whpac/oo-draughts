#include "king_pawn.hpp"

KingPawn::KingPawn(Board *board, PawnColor color) {
    this->board = board;
    this->color = color;
    this->type = king;
}

bool KingPawn::canBeMoved(Position from, Position to) {
    int d_row = to.getRow() - from.getRow();
    int d_col = to.getCol() - from.getCol();
    int dir_row = d_row / abs(d_row);
    int dir_col = d_col / abs(d_col);

    // Prevent from moves other than at angle 45 deg
    if(abs(d_row) != abs(d_col)) return false;

    // Ensure that the destination field is empty
    PawnPtr dest = this->board->getPawnAt(to);
    if(!Pawn::isEmpty(*dest)) return false;

    // Execute for each intermediate field
    // And ensure that king will kill no more than 1 pawn
    int killed_pawns = 0;
    for(int i = 1; i < abs(d_row); i++){
        // Check the field
        Position intermediate(
                from.getRow() + i * dir_row,
                from.getCol() + i * dir_col
                );
        PawnPtr intermediate_pawn = this->board->getPawnAt(intermediate);

        // Can kill only opponent's pawns
        if(this->isOpposite(intermediate_pawn)) killed_pawns++;
        if(intermediate_pawn->getColor() == this->color) return false;
    }

    if(killed_pawns > 1) return false;

    return true;
}

PawnPtr KingPawn::toPtr() {
    return make_shared<KingPawn>(*this);
}

bool KingPawn::canTransform(Position pos) {
    return false;
}

PawnPtr KingPawn::getTransform() {
    return this->toPtr();
}

bool KingPawn::canKill(Position pos) {
    int d_col[] = {-1, -1, 1, 1};
    int d_row[] = {-1, 1, -1, 1};

    for(int i = 0; i < 4; i++){
        bool found_pawn_to_kill = false;
        for(int j = 1; j < this->board->getSize(); j++){
            Position intermediate(
                    pos.getRow() + j*d_row[i],
                    pos.getCol() + j*d_col[i]
                    );
            PawnPtr neighbour = this->board->getPawnAt(intermediate);
            if(Pawn::isEmpty(*neighbour)){
                if(found_pawn_to_kill) return true;
                else continue;
            }else{  // The field is not empty
                // There can be only opponent's pawn on the way so break
                // Also, two opponent's pawns make an illegal move
                if(!this->isOpposite(neighbour)
                    || found_pawn_to_kill) break;

                found_pawn_to_kill = true;
            }
        }
    }

    return false;
}


