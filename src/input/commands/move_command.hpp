#ifndef INPUT_MOVE_COMMAND_H
#define INPUT_MOVE_COMMAND_H

#include "command.hpp"
#include "../../board/position.hpp"

class MoveCommand : public Command {

    public: MoveCommand(Position from, Position to);

    public: explicit MoveCommand(Command cmd);

    public: Position getFrom();

    public: Position getTo();
};


#endif
