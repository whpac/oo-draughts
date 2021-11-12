#include "console_view.hpp"
#include<iostream>

using namespace std;

ConsoleView::ConsoleView() {
    this->message = "";
}

void ConsoleView::displayBoard(Board& board){
    int size = board.getSize();
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            Position pos(row, col);
            PawnPtr p = board.getPawnAt(pos);

            switch(p->getColor()){
                case white:
                    cout << "w";
                    break;
                case black:
                    cout << "b";
                    break;
                default:
                    cout << ".";
                    break;
            }
        }
        cout << endl;
    }

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