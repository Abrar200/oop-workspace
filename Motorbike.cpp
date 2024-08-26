#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    return static_cast<int>(Vehicle::getParkingDuration() * 0.85); // 15% reduction
}