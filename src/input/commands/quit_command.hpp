#ifndef INPUT_QUIT_COMMAND_HPP
#define INPUT_QUIT_COMMAND_HPP

#include "command.hpp"

class QuitCommand : public Command {

    public: QuitCommand();

    public: explicit QuitCommand(Command cmd);

};


#endif
