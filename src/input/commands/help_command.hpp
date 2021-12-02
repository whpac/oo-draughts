#ifndef INPUT_HELP_COMMAND_H
#define INPUT_HELP_COMMAND_H

#include "command.hpp"

class HelpCommand : public Command {

    public: HelpCommand();

    public: explicit HelpCommand(Command cmd);

};

#endif
