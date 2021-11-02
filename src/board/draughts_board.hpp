#ifndef DRAUGHTS_BOARD_H
#define DRAUGHTS_BOARD_H

class DraughtsBoard;

#include "board.hpp"
#include "pieces/normal_pawn.hpp"

class DraughtsBoard : public Board {

    public: explicit DraughtsBoard(int size);

    /** Initializes the board with pawns */
    protected: void initialize();

    /**
     * Checks whether the given field is legal in the game
     * @param pos The position
     */
    protected: bool isPlayableField(Position pos) override;

    public: bool movePawn(Position from, Position to) override;

    /**
     * Kills all pawns along the move. Returns the number of pawns killed
     * @param from The beginning of the move
     * @param to The end of the move
     */
    protected: int killPawnsAlongMove(Position from, Position to);
};

#endif