#include "board/draughts_board.hpp"
#include "view/console.hpp"

int main(){
    Board board = DraughtsBoard(8);
    Console console;
    console.displayBoard(board);
    return 0;
}