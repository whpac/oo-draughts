#include "help_command.hpp"

HelpCommand::HelpCommand() {
    this->type = CommandType::help;
}

HelpCommand::HelpCommand(Command cmd) : Command(cmd) {
    if(cmd.getType() != CommandType::help) return;
}