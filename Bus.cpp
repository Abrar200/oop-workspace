#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    return static_cast<int>(Vehicle::getParkingDuration() * 0.75); // 25% reduction
}