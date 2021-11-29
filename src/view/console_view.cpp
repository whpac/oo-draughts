#include "console_view.hpp"
#include<iostream>

using namespace std;

ConsoleView::ConsoleView() {
    this->message = "";
}

void ConsoleView::displayBoard(Board& board){
    // Print header
    cout << "\033[2J\033[H";    // Clear screen and place cursor at (0, 0)
    cout << "\033[0;33mDRAUGHTS\033[0m ";   // Print in orange
    cout << "by Marcin Szwarc" << endl;
    cout << "\033[1;30mgithub.com/whpac/oo-draughts\033[0m";   // Print in gray
    cout << endl << endl << endl;

    // Then the board
    int size = board.getSize();
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            Position pos(row, col);
            PawnPtr p = board.getPawnAt(pos);
            PawnType type = p->getType();

            switch(p->getColor()){
                case white:
                    cout << (type == king ? "W" : "w");
                    break;
                case black:
                    cout << (type == king ? "B" : "b");
                    break;
                default:
                    cout << ".";
                    break;
            }
        }
        cout << endl;
    }

    // And finally some metadata
    cout << "WHITE: " << board.countPawnsOfColor(white) << endl;
    cout << "BLACK: " << board.countPawnsOfColor(black) << endl;
    cout
        << "Next player: "
        << (board.getNextPlayer() == white ? "WHITE" : "BLACK") << endl;

    if(!this->message.empty()){
        cout << this->message << endl;
    }
    this->clearMessage();
}

void ConsoleView::setMessage(string new_message) {
    this->message = std::move(new_message);
}

void ConsoleView::clearMessage() {
    this->message = "";
}