#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "../board/board.hpp"

class ConsoleView {
    protected: string message;

    public: ConsoleView();

    /**
     * Displays the board
     * @param board The board to display
     */
    public: void displayBoard(Board& board);

    /**
     * Sets a message to be displayed under the next board
     * @param new_message The message
     */
    public: void setMessage(string new_message);

    /**
     * Orders the view not to show the message
     * under the next board
     */
    public: void clearMessage();

    /**
     * Displays the manual
     */
    public: void displayHelp();

    /**
     * Responds to an unknown command
     */
    public: void respondToUnknownCommand();

};

#endif