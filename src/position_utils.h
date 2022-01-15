#ifndef ROVER_POSITION_UTILS_H
#define ROVER_POSITION_UTILS_H

#include <map>

using coordinate_t = int; // TODO

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

const static size_t number_of_directions = 4;


Direction get_direction_of_value(unsigned long value);

Direction get_direction_turned_right(const Direction &direction);

Direction get_direction_turned_left(const Direction &direction);


class Point;
using Vector = Point;

class Point {
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    coordinate_t x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(coordinate_t x, coordinate_t y) : x(x), y(y) {}

    Point operator+(const Vector &v) const {
        return {x + v.x, y + v.y};
    }

    coordinate_t get_x() {
        return x;
    }

    coordinate_t get_y() {
        return y;
    }
};

class Position {
    friend std::ostream &operator<<(std::ostream &os, const Position &position);

    Point coordinates;
    Direction direction;

public:
    Position() {
        direction = NORTH; // TODO żeby nie krzyczało że niezainicjowane
    }

    Position(Point coordinates, Direction direction) : coordinates(coordinates), direction(direction) {}

    Point get_coordinates() {
        return coordinates;
    }

    Direction &get_direction() {
        return direction;
    }

    void set_coordinates(Point _coordinates) {
        coordinates = _coordinates;
    }
};

Vector get_vector_of_direction(const Direction &direction);

#endif //ROVER_POSITION_UTILS_H
