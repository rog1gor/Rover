#ifndef ROVER_POSITION_UTILS_H
#define ROVER_POSITION_UTILS_H

using coordinate_t = int; // TODO

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

const static size_t number_of_directions = 4;

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

class Point;
using Vector = Point;

class Point {
    coordinate_t x, y;
public:
    constexpr Point() {
        x = 0;
        y = 0;
    }

    constexpr Point(coordinate_t x, coordinate_t y) : x(x), y(y) {}

    constexpr Point operator+(const Vector &p) const {
        return {x + p.x, y + p.y};
    }
};

class Position {
    Point coordinates;
    Direction direction;

public:
    Position() {
        direction = NORTH; // TODO żeby nie krzyczało że niezainicjowane
    }

    Position(Point coordinates, Direction direction) : coordinates(coordinates), direction(direction) {}
};


#endif //ROVER_POSITION_UTILS_H
