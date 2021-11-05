#include "empty_field.hpp"

EmptyField::EmptyField(bool in_bounds) {
    this->color = in_bounds ? no_pawn : out_of_bounds;
}

bool EmptyField::canBeMoved(Position from, Position to) {
    return false;   // empty fields shouldn't be moved
}

PawnPtr EmptyField::makePtr(bool in_bounds) {
    return std::make_shared<EmptyField>(in_bounds);
}

bool EmptyField::canTransform(Position pos) {
    return false;
}

PawnPtr EmptyField::getTransform() {
    return std::make_shared<EmptyField>(*this);
}

bool EmptyField::canKill(Position pos) {
    return false;   // empty fields cannot kill anything
}
