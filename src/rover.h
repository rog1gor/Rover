#ifndef ROVER_ROVER_H
#define ROVER_ROVER_H

#include <map>
#include "command.h"

class RoverBuilder;

class Rover {
    friend RoverBuilder;
    friend std::ostream &operator<<(std::ostream &os, const Rover &rover);

    std::map<char, command_ptr> commands_map;
    Position position;
    sensors_container_t sensors;

    bool is_landed = false;
    bool is_stopped = false;

    void add_sensor(sensor_ptr &&sensor);

    void program_command(const char command_name, command_ptr &&command);

public:
    Rover() : commands_map(), sensors() {};

    void execute(const std::string &commands);

    void land(Point coordinates, Direction direction);
};

class RoverBuilder {
    Rover rover;
public:
    RoverBuilder &add_sensor(sensor_ptr &&sensor);

    RoverBuilder &program_command(const char command_name, command_ptr &&command);

    RoverBuilder &program_command(const char command_name, const command_ptr &command);

    Rover &&build();
};


#endif //ROVER_ROVER_H
