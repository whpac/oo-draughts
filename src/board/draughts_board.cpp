#include "draughts_board.hpp"
#include "pieces/empty_field.hpp"

DraughtsBoard::DraughtsBoard(int size) : Board(size) {
    this->initialize();
}

void DraughtsBoard::initialize(){
    // Place white pawns
    for(int row = 0; row < this->boardSize / 2 - 1; row++){
        for(int col = 0; col < this->boardSize; col++){
            if(!this->isPlayableField(Position(row, col))) continue;
            NormalPawn p(this, white);
            this->setPawnAt(Position(row, col), p.toPtr());
        }
    }

    // Place black pawns
    for(int row = this->boardSize / 2 + 1; row < this->boardSize; row++){
        for(int col = 0; col < this->boardSize; col++){
            if(!this->isPlayableField(Position(row, col))) continue;
            NormalPawn p(this, black);
            this->setPawnAt(Position(row, col), p.toPtr());
        }
    }
}

bool DraughtsBoard::isPlayableField(Position pos){
    if(!this->isPositionWithinBounds(pos)) return false;
    return (pos.getRow() + pos.getCol()) % 2 == 1;
}

bool DraughtsBoard::movePawn(Position from, Position to) {
    if(!this->isSourceFieldPermitted(from)) return false;
    PawnColor currentPlayer = this->nextPlayer;

    if(!Board::movePawn(from, to)) return false;
    int killed_pawns = this->killPawnsAlongMove(from, to);

    if(killed_pawns > 0){
        PawnPtr moved_pawn = this->getPawnAt(to);

        // If the moved pawn can perform further kill, prolong the current turn
        if(moved_pawn->canKill(to)) {
            this->nextPlayer = currentPlayer;
            this->restrictMoveTo(to);
            return true;
        }
    }

    this->unrestrictMove();
    return true;
}

int DraughtsBoard::killPawnsAlongMove(Position from, Position to) {
    int r_offset = to.getRow() - from.getRow();
    int c_offset = to.getCol() - from.getCol();
    int killed_pawns = 0;

    // Skip both ends of the move
    for(int i = 1; i < abs(r_offset); i++){
        Position middle(
                from.getRow() + i * (r_offset > 0 ? 1 : -1),
                from.getCol() + i * (c_offset > 0 ? 1 : -1)
                );
        PawnPtr current_pawn = this->getPawnAt(middle);
        if(Pawn::isEmpty(*current_pawn)) continue;

        // Increase the killed pawns counter
        killed_pawns++;
        this->setPawnAt(middle, EmptyField::makePtr(true));
    }
    return killed_pawns;
}

void DraughtsBoard::restrictMoveTo(Position pos){
    this->isMoveRestricted = true;
    this->forcedSourceField = pos;
}

void DraughtsBoard::unrestrictMove() {
    this->isMoveRestricted = false;
}

bool DraughtsBoard::isSourceFieldPermitted(Position pos) {
    if(!this->isMoveRestricted) return true;
    return pos == this->forcedSourceField;
}