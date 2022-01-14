#include "position_utils.h"


Direction get_direction_of_value(unsigned long value) {
    if (value == 0) {
        return NORTH;
    }
    else if (value == 1) {
        return EAST;
    }
    else if (value == 2) {
        return SOUTH;
    }
    else if (value == 3) {
        return WEST;
    }
    else {
        // TODO do poprawienia
        throw std::exception();
    }
}

Direction get_direction_turned_right(const Direction &direction) {
    return get_direction_of_value((direction + 1) % number_of_directions);
}

Direction get_direction_turned_left(const Direction &direction) {
    return get_direction_of_value((direction - 1) % number_of_directions);
}

Vector get_vector_of_direction(const Direction &direction) {
    static std::map<Direction, Vector> map = {
            {NORTH, {0, 1}},
            {EAST, {1, 0}},
            {SOUTH, {0, -1}},
            {WEST, {-1, 0}}
    };

    return map[direction];
}

