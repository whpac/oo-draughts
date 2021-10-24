#ifndef BOARD_H
#define BOARD_H

class Board;

#include<vector>
#include<memory>
#include "position.hpp"
#include "pieces/pawn.hpp"

using namespace std;

class Board {
    protected: int boardSize;
    protected: vector<shared_ptr<Pawn>> board;

public:
    /**
     * Creates a new instance of board with a specified size.
     * @param size The length of board side
     */
    explicit Board(int size);

    /** Returns the board size */
    int getSize() const;

    /**
     * Returns a pawn at the specified position.
     * @param pos The position
     */
    shared_ptr<Pawn> getPawnAt(Position pos);

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
    protected: int positionToIndex(Position pos) const;

    /**
     * Checks whether the position is within the board
     * @param pos The position
     */
    protected: bool isPositionWithinBounds(Position pos) const;

    /**
     * Checks whether the given field is legal in the game
     * @param pos The position
     */
    protected: virtual bool isPlayableField(Position pos);
};

#endif