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
    protected: vector<PawnPtr> board;
    protected: PawnColor nextPlayer = PawnColor::white;

public:
    /**
     * Creates a new instance of board with a specified size.
     * @param size The length of board side
     */
    public: explicit Board(int size);

    /** Returns the board size */
    public: int getSize() const;

    /**
     * Returns a pawn at the specified position.
     * @param pos The position
     */
    public: PawnPtr getPawnAt(Position pos);

    /**
     * Places the pawn at the specified position.
     * @param pos The position
     * @param pawn The pawn
     */
    protected: void setPawnAt(Position pos, PawnPtr pawn);

    /**
     * Moves pawn between fields
     * @param from The source field
     * @param to The destination field
     * @return Whether the move was successful
     */
    public: virtual bool movePawn(Position from, Position to);

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
    public: virtual bool isPlayableField(Position pos);

    /**
     * Counts pawns of the specified color
     * @param color The color of pawns to be counted
     */
    public: int countPawnsOfColor(PawnColor color);

    /** Returns the color of the next player */
    public: PawnColor getNextPlayer();

    /** Checks whether the game is over */
    public: virtual bool isGameOver() = 0;

    /** Returns color of a player who won the game */
    public: virtual PawnColor whoWon() = 0;
};

#endif