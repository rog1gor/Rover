#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include <stdexcept>

class RoverNotLanded : public std::runtime_error {
public:
    RoverNotLanded (const char* what) : std::runtime_error(what) {}
};

#endif // PROJECT_EXCEPTIONS_H
