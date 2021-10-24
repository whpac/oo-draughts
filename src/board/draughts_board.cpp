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