#include "board/draughts_board.hpp"
#include "view/console_view.hpp"
#include "input/console_input.hpp"
#include "input/commands/move_command.hpp"

void performMove(Board& board, Command cmd);

int main(){
    DraughtsBoard board = DraughtsBoard(8);
    ConsoleView console;
    ConsoleInput input;

    bool cont = true;
    while(cont){
        console.displayBoard(board);
        Command cmd = input.getCommand();
        switch(cmd.getType()) {
            case CommandType::move:
                performMove(board, cmd);
                break;
            case CommandType::undo:
                break;
            case CommandType::quit:
                cont = false;
                break;
            case CommandType::unknown:
                break;
        }
    }

    return 0;
}

void performMove(Board& board, Command cmd){
    MoveCommand mv_cmd = (MoveCommand) cmd;
    board.movePawn(mv_cmd.getFrom(), mv_cmd.getTo());
}