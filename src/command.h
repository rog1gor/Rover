#ifndef ROVER_COMMAND_H
#define ROVER_COMMAND_H

#include <memory>
#include <vector>
#include "sensor.h"

using command_result_t = std::pair<Position, bool>;

class Command {
protected:
    bool check_all_sensors(Position position, const sensors_container_t &sensors);

public:
    virtual command_result_t execute(Position position, const sensors_container_t &sensors);
};

using command_ptr = std::shared_ptr<Command>;

class MoveForward : public Command {
    command_result_t execute(Position position, const sensors_container_t &sensors) override;
};

class MoveBackward : public Command {
    command_result_t execute(Position position, const sensors_container_t &sensors) override;
};

class RotateRight : public Command {
    command_result_t execute(Position position, const sensors_container_t &sensors) override;
};

class RotateLeft : public Command {
    command_result_t execute(Position position, const sensors_container_t &sensors) override;
};

class Compose : public Command {
    command_result_t execute(Position position, const sensors_container_t &sensors) override;
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
