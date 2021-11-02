#ifndef PAWN_H
#define PAWN_H

#define PawnPtr std::shared_ptr<Pawn>

class Pawn;

enum PawnColor {
    black,
    white,
    no_pawn   // means no pawn at the field
};

#include "../board.hpp"
#include "../position.hpp"

class Pawn {
    protected: PawnColor color = no_pawn;
    protected: Board* board = nullptr;

public:
    /**
     * Checks whether the pawn can be moved between the specified positions.
     * 
     * @param from The beginning position of the move
     * @param to The ending position of the move
     */
    public: virtual bool canBeMoved(Position from, Position to) = 0;

    /** Returns the pawn color */
    public: PawnColor getColor();

    /**
     * Checks whether the pawn can transform into another
     * @param pos The current position of the pawn
     */
    public: virtual bool canTransform(Position pos) = 0;

    /** Gets a pawn that this one can transform into */
    public: virtual PawnPtr getTransform() = 0;

    /** Checks whether the passed pawn represents an empty field */
    public: static bool isEmpty(Pawn& pawn);

    /**
     * Returns an opposite color
     * @param color Color
     */
    public: static PawnColor getOppositeColor(PawnColor color);
};

#endif