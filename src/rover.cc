#include <iostream>
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


void Rover::add_sensor(sensor_ptr &&sensor) {
    sensors.push_back(sensor);
}

void Rover::program_command(const char command_name, command_ptr &&command) {
    commands_map[command_name] = command; // TODO czy nazwy mogą się powtarzać?
}

// TODO niedokończone
void Rover::execute(const std::string &commands) {
    if (!is_landed) {
//        throw std::exception(); // TODO
    }

    is_stopped = false;

    for (auto command_name : commands) {
        if (!commands_map.contains(command_name)) {
            is_stopped = true;
            break;
        }
        auto command = commands_map[command_name];
        CommandResult command_result = command->execute(position, sensors);
        std::cout << position.get_coordinates().get_x() << ", " << position.get_coordinates().get_y() << " | "
            << command_result.get_position().get_coordinates().get_x() << ", " << command_result.get_position().get_coordinates().get_y() << "\n";
        position = command_result.get_position();
        is_stopped = command_result.get_is_stopped();
    }
}