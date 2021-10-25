#include "move_command.hpp"

MoveCommand::MoveCommand(Position from, Position to) : Command() {
    this->type = move;
    this->from = from;
    this->to = to;
}

MoveCommand::MoveCommand(Command cmd) : Command(cmd) {
    if(this->type != CommandType::move) return;
}

Position MoveCommand::getFrom() {
    return this->from;
}

Position MoveCommand::getTo() {
    return this->to;
}
