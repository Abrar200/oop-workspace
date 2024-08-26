#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    return static_cast<int>(Vehicle::getParkingDuration() * 0.9); // 10% reduction
}