#ifndef INPUT_COMMAND_H
#define INPUT_COMMAND_H

#include "../../board/position.hpp"

enum CommandType {
    unknown,
    move,
    help,
    quit
};

/** A base class for all user commands */
class Command {
    protected: CommandType type = unknown;
    protected: Position from;
    protected: Position to;

    /** Returns the command type */
    public: CommandType getType();
};

#endif
