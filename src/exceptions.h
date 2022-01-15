#include <stdexcept>

class RoverNotLanded : public std::exception {
    const char* what() const throw() {
        return "Rover did not land";
    }
};
