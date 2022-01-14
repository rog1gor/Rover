#ifndef ROVER_SENSOR_H
#define ROVER_SENSOR_H

#include "position_utils.h"

class Sensor {
    virtual bool is_safe(coordinate_t x, coordinate_t y) {
        return true;
    };
};

using sensor_ptr = std::shared_ptr<Sensor>;


#endif //ROVER_SENSOR_H
