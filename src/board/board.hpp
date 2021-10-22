#ifndef BOARD_H
#define BOARD_H

class Board;
using namespace std;

#include<cstddef>
#include<vector>
#include "position.hpp"
#include "pieces/pawn.hpp"

class Board {
    protected: int boardSize;
    protected: vector<Pawn*> board;

public:
    /**
     * Creates a new instance of board with a specified size.
     * @param size The legth of board side
     */
    Board(int size);

    /** Returns the board size */
    int getSize();

    /**
     * Returns a pawn at the specified position.
     * @param pos The position
     */
    Pawn& getPawnAt(Position pos);

    /**
     * Places the pawn at the specified position.
     * @param pos The position
     * @param pawn The pawn
     */
    void setPawnAt(Position pos, Pawn& pawn);

    /**
     * Converts a `Position` object into an one-dimensional index
     * @param pos The position
     */
    protected: int positionToIndex(Position pos);

    /**
     * Checks whether the position is within the board
     * @param pos The position
     */
    protected: bool isPositionWithinBounds(Position pos);
};

#endif