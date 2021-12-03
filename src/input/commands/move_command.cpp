#include "move_command.hpp"
#include<stdexcept>

MoveCommand::MoveCommand(Position from, Position to) : Command() {
    this->type = move;
    this->from = from;
    this->to = to;
}

MoveCommand::MoveCommand(Command cmd) : Command(cmd) {
    if(cmd.getType() != CommandType::move) throw std::domain_error("Invalid command type");
}

Position MoveCommand::getFrom() {
    return this->from;
}

Position MoveCommand::getTo() {
    return this->to;
}
