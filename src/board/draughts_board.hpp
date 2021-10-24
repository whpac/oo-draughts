#ifndef DRAUGHTS_BOARD_H
#define DRAUGHTS_BOARD_H

class DraughtsBoard;

#include "board.hpp"

class DraughtsBoard : public Board {

public:
    DraughtsBoard(int size);

    /** Initializes the board with pawns */
    protected: void initialize();

    /**
     * Checks whether the given field is legal in the game
     * @param pos The position
     */
    protected: bool isPlayableField(Position pos) override;
};

#endif