#include <iostream>
#include "rover.h"
#include "project_exceptions.h"

std::ostream &operator<<(std::ostream &os, const Rover &rover) {
    if (!rover.is_landed) {
        os << "unknown";
        return os;
    }

    os << rover.position;

    if (rover.is_stopped) {
        os << " stopped";
    }

    return os;
}


RoverBuilder &RoverBuilder::add_sensor(sensor_ptr &&sensor) {
    rover.add_sensor(std::move(sensor));
    return *this;
}

RoverBuilder &RoverBuilder::program_command(const char command_name, command_ptr &&command) {
    rover.program_command(command_name, std::move(command));
    return *this;
}

RoverBuilder &RoverBuilder::program_command(const char command_name, command_ptr &command) {
    rover.program_command(command_name, std::move(command));
    return *this;
}

Rover &&RoverBuilder::build() {
    return std::move(rover);
}


void Rover::add_sensor(sensor_ptr &&sensor) {
    sensors.push_back(sensor);
}

void Rover::program_command(const char command_name, command_ptr &&command) {
    commands_map[command_name] = command;
}

void Rover::land(Point coordinates, Direction direction) {
    position = {coordinates, direction};
    is_landed = true;
    is_stopped = false;
}

void Rover::execute(const std::string &commands) {
    if (!is_landed) {
        throw RoverNotLanded("Rover did not land");
    }

    is_stopped = false;

    for (auto command_name : commands) {
        if (!commands_map.contains(command_name)) {
            is_stopped = true;
            break;
        }
        auto command = commands_map[command_name];
        CommandResult command_result = command->execute(position, sensors);
        position = command_result.get_position();
        is_stopped = command_result.get_is_stopped();
    }
}
