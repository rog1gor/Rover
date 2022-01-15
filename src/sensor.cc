#include <memory>
#include <vector>
#include "sensor.h"

bool check_all_sensors(Position position, const sensors_container_t &sensors) {
    for (const auto& sensor : sensors) {
        if (!sensor->is_safe(position.get_coordinates().get_x(), position.get_coordinates().get_y())) {
            return false;
        }
    }
    return true;
}
