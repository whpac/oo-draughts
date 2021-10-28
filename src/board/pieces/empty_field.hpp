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
};

#endif
