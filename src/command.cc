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

namespace {
    CommandResult executed_result(Position new_position, Position old_position, const sensors_container_t &sensors) {
        if (check_all_sensors(new_position, sensors)) {
            return {new_position, false};
        }
        else {
            return {old_position, true};
        }
    }
}

CommandResult MoveForward::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;
    Vector move_vector = get_vector_of_direction(position.get_direction());
    new_position.set_coordinates(new_position.get_coordinates() + move_vector);

    return executed_result(new_position, position, sensors);
}

CommandResult MoveBackward::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;
    Vector move_vector = get_vector_of_direction(get_opposite_direction(position.get_direction()));
    new_position.set_coordinates(new_position.get_coordinates() + move_vector);

    return executed_result(new_position, position, sensors);
}

CommandResult RotateRight::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;
    new_position.set_direction(get_direction_turned_right(position.get_direction()));

    return executed_result(new_position, position, sensors);
}

CommandResult RotateLeft::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;
    new_position.set_direction(get_direction_turned_left(position.get_direction()));

    return executed_result(new_position, position, sensors);
}

CommandResult Compose::execute(Position position, const sensors_container_t &sensors) {
    Position new_position = position;

    for (auto command : commands) {
        CommandResult command_result = command->execute(new_position, sensors);

        if (command_result.get_is_stopped()) {
            return {new_position, true};
        }

        new_position = command_result.get_position();
    }

    return {new_position, false};
}
