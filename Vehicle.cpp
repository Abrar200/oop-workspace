#include "Vehicle.h"

Vehicle::Vehicle(int vehicleId) : id(vehicleId), timeOfEntry(std::time(nullptr)) {}

int Vehicle::getID() const {
    return id;
}

int Vehicle::getParkingDuration() const {
    return static_cast<int>(std::difftime(std::time(nullptr), timeOfEntry));
}