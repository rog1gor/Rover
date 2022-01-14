#ifndef ROVER_ROVER_H
#define ROVER_ROVER_H

#include <map>
#include "command.h"
#include "sensor.h"
#include "position_utils.h"

class RoverBuilder;

class Rover {
    friend RoverBuilder;

    std::map<char, command_ptr> commands_map;
    Position position;
    std::vector<sensor_ptr> sensors;
public:

};

class RoverBuilder {

};


#endif //ROVER_ROVER_H
