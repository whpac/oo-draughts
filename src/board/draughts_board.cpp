#include "draughts_board.hpp"

DraughtsBoard::DraughtsBoard(int size) : Board(size) {
    this->initialize();
}

void DraughtsBoard::initialize(){
    // Place white pawns
    for(int row = 0; row < this->boardSize / 2 - 1; row++){
        for(int col = 0; col < this->boardSize; col++){
            if(!this->isPlayableField(Position(row, col))) continue;
            NormalPawn p(this, white);
            this->setPawnAt(Position(row, col), make_shared<NormalPawn>(p));
        }
    }

    // Place black pawns
    for(int row = this->boardSize / 2 + 1; row < this->boardSize; row++){
        for(int col = 0; col < this->boardSize; col++){
            if(!this->isPlayableField(Position(row, col))) continue;
            NormalPawn p(this, black);
            this->setPawnAt(Position(row, col), make_shared<NormalPawn>(p));
        }
    }
}

bool DraughtsBoard::isPlayableField(Position pos){
    if(!this->isPositionWithinBounds(pos)) return false;
    return (pos.getRow() + pos.getCol()) % 2 == 1;
}

bool DraughtsBoard::movePawn(Position from, Position to) {
    if(!Board::movePawn(from, to)) return false;
    this->killPawnsAlongMove(from, to);
    return true;
}

void DraughtsBoard::killPawnsAlongMove(Position from, Position to) {
    int r_offset = to.getRow() - from.getRow();
    int c_offset = to.getCol() - from.getCol();

    // Skip both ends of the move
    for(int i = 1; i < abs(r_offset); i++){
        Position middle(
                from.getRow() + i * (r_offset > 0 ? 1 : -1),
                from.getCol() + i * (c_offset > 0 ? 1 : -1)
                );
        this->setPawnAt(middle, make_shared<NormalPawn>(this, no_pawn));
    }
}