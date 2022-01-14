#include "command.h"


command_ptr move_forward() {
    return std::make_shared<MoveForward>();
}

command_ptr move_backward() {
    return std::make_shared<MoveBackward>();
}

command_ptr rotate_left() {
    return std::make_shared<RotateLeft>();
}

command_ptr rotate_right() {
    return std::make_shared<RotateRight>();
}

command_ptr compose(std::initializer_list<command_ptr> commands) {
    return std::make_shared<Compose>(commands);
}

Compose::Compose(std::initializer_list<command_ptr> commands) : commands(commands) {}