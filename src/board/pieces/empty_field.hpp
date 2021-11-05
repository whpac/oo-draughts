#ifndef EMPTY_FIELD_H
#define EMPTY_FIELD_H

#include "pawn.hpp"

class EmptyField : public Pawn {

    /**
     * Creates an empty field
     * @param in_bounds Whether the empty field is in bounds of the board
     */
    public: EmptyField(bool in_bounds);

    public: bool canBeMoved(Position from, Position to) override;

    /**
     * Creates an instance of EmptyField wrapped as PawnPtr
     * @param in_bounds Whether the empty field is in bounds of the board
     */
    public: static PawnPtr makePtr(bool in_bounds);

    public: bool canTransform(Position pos) override;

    public: PawnPtr getTransform() override;

    public: bool canKill(Position pos) override;
};

#endif
