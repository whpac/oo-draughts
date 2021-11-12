#ifndef KING_PAWN_H
#define KING_PAWN_H

#include "pawn.hpp"
#include<cstdlib>

class KingPawn : public Pawn {

    /**
     * Creates an instance of a new king pawn
     * @param board The board the pawn is on
     * @param color Color of the pawn
     */
    public: KingPawn(Board* board, PawnColor color);

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