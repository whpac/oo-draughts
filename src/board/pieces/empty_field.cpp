#include "empty_field.hpp"

EmptyField::EmptyField() {
    this->color = no_pawn;
}

bool EmptyField::canBeMoved(Position from, Position to) {
    return false;   // empty fields shouldn't be moved
}

PawnPtr EmptyField::makePtr() {
    return std::make_shared<EmptyField>();
}
