#include "board/draughts_board.hpp"
#include "view/console_view.hpp"
#include "input/console_input.hpp"
#include "input/commands/move_command.hpp"

bool performMove(Board& board, Command cmd);

int main(){
    DraughtsBoard board(6);
    ConsoleView console;
    ConsoleInput input;

    bool cont = true;
    while(cont){
        console.displayBoard(board);
        Command cmd = input.getCommand();
        switch(cmd.getType()) {
            case CommandType::move:
                if(!performMove(board, cmd)){
                    console.setMessage("The attempted move was not legal.");
                }
                break;
            case CommandType::undo:
                break;
            case CommandType::quit:
                cont = false;
                break;
            case CommandType::unknown:
                break;
        }
        if(board.isGameOver()){
            console.setMessage("Game over! GRAY won.");
            console.displayBoard(board);
            cont = false;
        }
    }

    return 0;
}

bool performMove(Board& board, Command cmd){
    MoveCommand mv_cmd = (MoveCommand) cmd;
    bool success = board.movePawn(mv_cmd.getFrom(), mv_cmd.getTo());
    return success;
}