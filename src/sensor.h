#ifndef ROVER_SENSOR_H
#define ROVER_SENSOR_H

#include "position_utils.h"

class Sensor {
public:
    virtual bool is_safe(coordinate_t x, coordinate_t y) = 0;
};

using sensor_ptr = std::shared_ptr<Sensor>;
using sensors_container_t = std::vector<sensor_ptr>;

bool check_all_sensors(Position position, const sensors_container_t &sensors);

#endif //ROVER_SENSOR_H
