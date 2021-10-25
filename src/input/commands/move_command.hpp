#ifndef INPUT_MOVE_COMMAND_H
#define INPUT_MOVE_COMMAND_H

#include "command.hpp"
#include "../../board/position.hpp"

class MoveCommand : public Command {

    public: MoveCommand(Position from, Position to);

    public: explicit MoveCommand(Command cmd);

    /** Returns the origin of the move */
    public: Position getFrom();

    /** Returns the destination of the move */
    public: Position getTo();
};


#endif
