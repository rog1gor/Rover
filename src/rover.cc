#include "rover.h"


RoverBuilder &RoverBuilder::add_sensor(sensor_ptr &&sensor) {
    rover.add_sensor(std::move(sensor));
    return *this;
}

RoverBuilder &RoverBuilder::program_command(const char command_name, command_ptr &&command) {
    rover.program_command(command_name, std::move(command));
    return *this;
}

Rover &&RoverBuilder::build() {
    return std::move(rover);
}