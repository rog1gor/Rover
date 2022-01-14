#ifndef ROVER_SENSOR_H
#define ROVER_SENSOR_H

class Sensor {
    virtual bool is_safe(coordinate_t x, coordinate_t y) {
        return true;
    };
};


#endif //ROVER_SENSOR_H
