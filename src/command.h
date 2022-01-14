#ifndef ROVER_COMMAND_H
#define ROVER_COMMAND_H

#include <memory>
#include <vector>


class Command {
public:
    virtual void execute() {

    }
};

using command_ptr = std::shared_ptr<Command>;

class MoveForward : public Command {
    void execute() override;
};

class MoveBackward : public Command {
    void execute() override;
};

class RotateRight : public Command {
    void execute() override;
};

class RotateLeft : public Command {
    void execute() override;
};

class Compose : public Command {
    void execute() override;
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
