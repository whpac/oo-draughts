#include "console_input.hpp"
#include "commands/move_command.hpp"
#include "commands/quit_command.hpp"

#include<iostream>

Command ConsoleInput::getCommand() {
    char c;
    std::cin >> c;

    switch(c){
        case 'm':
            int r_from, c_from, r_to, c_to;
            std::cin >> r_from >> c_from >> r_to >> c_to;
            return MoveCommand(Position(r_from, c_from), Position(r_to, c_to));
        case 'q':
            return QuitCommand();
        default:
            return {};
    }
}