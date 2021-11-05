#ifndef NORMAL_PAWN_H
#define NORMAL_PAWN_H

#include "pawn.hpp"
#include<cstdlib>

class NormalPawn : public Pawn {

    /**
     * Creates an instance of a new normal pawn
     * @param board The board the pawn is on
     * @param color Color of the pawn
     */
    public: NormalPawn(Board* board, PawnColor color);

    public: bool canBeMoved(Position from, Position to) override;

    /**
     * Converts the pawn into the PawnPtr
     */
    public: PawnPtr toPtr();

    public: bool canTransform(Position pos) override;

    public: PawnPtr getTransform() override;

    public: bool canKill(Position pos) override;
};

#endif