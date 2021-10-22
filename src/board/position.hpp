#ifndef POSITION_H
#define POSITION_H

class Position {
    protected: int row;
    protected: int col;

    public:
    /**
     * Creates a new instance of `Position`.
     * 
     * @param row The 'row' coordinate
     * @param col The 'column' coordinate
     */
    Position(int row, int col);

    /** Returns the 'row' coordinate */
    int getRow();

    /** Returns the 'column' coordinate */
    int getCol();
};

#endif