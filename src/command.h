#ifndef ROVER_COMMAND_H
#define ROVER_COMMAND_H

#include <memory>
#include <vector>
#include "sensor.h"

class CommandResult {
    Position position;
    bool is_stopped;

public:
    CommandResult(Position position, bool is_stopped) : position(position), is_stopped(is_stopped) {}

    Position get_position() {
        return position;
    }

    bool get_is_stopped() {
        return is_stopped;
    }
};

class Command {
public:
    virtual CommandResult execute(Position position, const sensors_container_t &sensors) = 0;
};

using command_ptr = std::shared_ptr<Command>;

class MoveForward : public Command {
    CommandResult execute(Position position, const sensors_container_t &sensors) override;
};

class MoveBackward : public Command {
    CommandResult execute(Position position, const sensors_container_t &sensors) override;
};

class RotateRight : public Command {
    CommandResult execute(Position position, const sensors_container_t &sensors) override;
};

class RotateLeft : public Command {
    CommandResult execute(Position position, const sensors_container_t &sensors) override;
};

class Compose : public Command {
    CommandResult execute(Position position, const sensors_container_t &sensors) override;
    std::vector<command_ptr> commands;
public:
    Compose(std::initializer_list<command_ptr> commands);
};

command_ptr move_forward();

command_ptr move_backward();

command_ptr rotate_left();

command_ptr rotate_right();

command_ptr compose(std::initializer_list<command_ptr> commands);


#endif //ROVER_COMMAND_H
