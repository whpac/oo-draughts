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
            case CommandType::help:
                // console.displayHelp();
                break;
            case CommandType::quit:
                cont = false;
                break;
            case CommandType::unknown:
                // console.unknownRequest();
                break;
        }
        if(board.isGameOver()){
            PawnColor winner = board.whoWon();
            if(winner == white) console.setMessage("Game over! WHITE won.");
            else if(winner == black) console.setMessage("Game over! BLACK won.");
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