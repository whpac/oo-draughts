#include "help_command.hpp"
#include<stdexcept>

HelpCommand::HelpCommand() {
    this->type = CommandType::help;
}

HelpCommand::HelpCommand(Command cmd) : Command(cmd) {
    if(cmd.getType() != CommandType::help) throw std::domain_error("Invalid command type");
}