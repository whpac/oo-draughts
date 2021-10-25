#include "board/draughts_board.hpp"
#include "view/console_view.hpp"
#include "input/console_input.hpp"
#include "input/commands/move_command.hpp"

int main(){
    DraughtsBoard board = DraughtsBoard(8);
    ConsoleView console;
    ConsoleInput input;

    Command cmd = input.getCommand();
    switch(cmd.getType()){
        case CommandType::move:
            MoveCommand mv_cmd = (MoveCommand)cmd;
            board.movePawn(mv_cmd.getFrom(), mv_cmd.getTo());
            break;
        case CommandType::undo:
            break;
        case CommandType::unknown:
            break;
    }

    console.displayBoard(board);
    return 0;
}