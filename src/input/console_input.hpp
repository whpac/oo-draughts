#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "commands/command.hpp"

class ConsoleInput {

    /**
     * Retrieves the command from the user
     */
    public: Command getCommand();
};


#endif
