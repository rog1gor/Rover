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

bool Command::check_all_sensors(Position position, const sensors_container_t &sensors) {
    for (const auto& sensor : sensors) {
        if (!sensor->is_safe(position.get_coordinates().get_x(), position.get_coordinates().get_y())) {
            return false;
        }
    }
    return true;
}

// TODO raczej niepotrzebne
CommandResult Command::execute(Position position, const sensors_container_t &sensors) {
    return CommandResult(Position(), {});
}

CommandResult MoveForward::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;
    Vector move_vector = get_vector_of_direction(position.get_direction());
    new_position.set_coordinates(new_position.get_coordinates() + move_vector);

    if (check_all_sensors(new_position, sensors)) {
        return {new_position, false};
    }
    else {
        return {position, true};
    }
}

CommandResult MoveBackward::execute(Position position, const sensors_container_t &sensors) {

}

CommandResult RotateRight::execute(Position position, const sensors_container_t &sensors) {

}

CommandResult RotateLeft::execute(Position position, const sensors_container_t &sensors) {

}

CommandResult Compose::execute(Position position, const sensors_container_t &sensors) {

}

