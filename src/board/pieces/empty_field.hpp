#ifndef EMPTY_FIELD_H
#define EMPTY_FIELD_H

#include "pawn.hpp"

class EmptyField : public Pawn {

    public: EmptyField();

    public: bool canBeMoved(Position from, Position to) override;

    /**
     * Creates an instance of EmptyField wrapped as PawnPtr
     */
    public: static PawnPtr makePtr();

    public: bool canTransform(Position pos) override;

    public: PawnPtr getTransform() override;

    public: bool canKill(Position pos) override;
};

#endif
