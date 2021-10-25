#include "console_view.hpp"
#include<cstdio>

void ConsoleView::displayBoard(Board& board){
    int size = board.getSize();
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            shared_ptr<Pawn> p = board.getPawnAt(Position(row, col));

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
}