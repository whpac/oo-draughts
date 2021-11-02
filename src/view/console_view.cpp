#include "console_view.hpp"
#include<cstdio>

void ConsoleView::displayBoard(Board& board){
    int size = board.getSize();
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            PawnPtr p = board.getPawnAt(Position(row, col));

            switch(p->getColor()){
                case white:
                    printf("w");
                    break;
                case black:
                    printf("b");
                    break;
                default:
                    printf(".");
                    break;
            }
        }
        printf("\n");
    }

    printf("WHITE: %d\n", board.countPawnsOfColor(white));
    printf("BLACK: %d\n", board.countPawnsOfColor(black));
    printf("Next player: %s\n", board.getNextPlayer() == white ? "WHITE" : "BLACK");
}
