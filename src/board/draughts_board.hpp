#ifndef DRAUGHTS_BOARD_H
#define DRAUGHTS_BOARD_H

class DraughtsBoard;

#include "board.hpp"
#include "pieces/normal_pawn.hpp"

class DraughtsBoard : public Board {
    protected: bool isMoveRestricted = false;
    protected: Position forcedSourceField;

    public: explicit DraughtsBoard(int size);

    public: bool movePawn(Position from, Position to) override;

    public: bool isGameOver() override;

    public: PawnColor whoWon() override;

    /** Initializes the board with pawns */
    protected: void initialize();

    /**
     * Checks whether the given field is legal in the game
     * @param pos The position
     */
    public: bool isPlayableField(Position pos) override;

    /**
     * Kills all pawns along the move. Returns the number of pawns killed
     * @param from The beginning of the move
     * @param to The end of the move
     */
    protected: int killPawnsAlongMove(Position from, Position to);

    /**
     * Restricts the moved pawn to one at the specified field
     */
    protected: void restrictMoveTo(Position pos);

    /** Lifts off the moved pawn restriction */
    protected: void unrestrictMove();

    /**
     * Checks whether the source field is not restricted
     */
    protected: bool isSourceFieldPermitted(Position pos);

    /**
     * Checks if there is a pawn in a given color than can kill
     * @param color The color of pawn to kill
     */
    protected: bool canAnyPawnKill(PawnColor color);
};

#endif