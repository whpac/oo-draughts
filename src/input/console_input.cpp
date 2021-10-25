#include "console_input.hpp"

Command ConsoleInput::getCommand() {
    return MoveCommand(Position(2, 1), Position(3, 2));
}