#ifndef NORMAL_PAWN_H
#define NORMAL_PAWN_H

#include "pawn.hpp"
#include<cstdlib>

class NormalPawn : public Pawn {

    public: NormalPawn(Board* board, PawnColor color);

    public: bool canBeMoved(Position from, Position to) override;
};

#endif