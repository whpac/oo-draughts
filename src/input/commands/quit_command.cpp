#include "quit_command.hpp"
#include<stdexcept>

QuitCommand::QuitCommand() {
    this->type = CommandType::quit;
}

QuitCommand::QuitCommand(Command cmd) : Command(cmd) {
    if(cmd.getType() != CommandType::quit) throw std::domain_error("Invalid command type");
}