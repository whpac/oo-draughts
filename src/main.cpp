#include "board/draughts_board.hpp"
#include "view/console_view.hpp"
#include "input/console_input.hpp"
#include "input/commands/move_command.hpp"
#include<stdexcept>

bool performMove(Board& board, Command cmd);

int main(int argc, char** argv){
    int size = 8;

    if(argc >= 2){
        size = strtol(argv[1], nullptr, 0);
    }

    DraughtsBoard board(size);
    ConsoleView console;
    ConsoleInput input;

    console.displayBoard(board);
    bool cont = true;
    while(cont){
        Command cmd = input.getCommand();
        switch(cmd.getType()) {
            case CommandType::move:
                if(!performMove(board, cmd)){
                    console.setMessage("The attempted move was not legal.");
                }
                console.displayBoard(board);
                break;
            case CommandType::help:
                console.displayHelp();
                break;
            case CommandType::quit:
                cont = false;
                break;
            case CommandType::unknown:
                console.respondToUnknownCommand();
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
    try {
        MoveCommand mv_cmd = MoveCommand(cmd);
        bool success = board.movePawn(mv_cmd.getFrom(), mv_cmd.getTo());
        return success;
    }catch(std::domain_error& e){
        return false;
    }
}