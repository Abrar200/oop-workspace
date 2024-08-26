#include "ParkingLot.h"
#include <algorithm>
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    vehicles.reserve(capacity);
}

int ParkingLot::getCount() const {
    return currentCount;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (currentCount < maxCapacity) {
        vehicles.push_back(vehicle);
        currentCount++;
    } else {
        std::cout << "The lot is full" << std::endl;
    }
}

void ParkingLot::unparkVehicle(int id) {
    auto it = std::find_if(vehicles.begin(), vehicles.end(),
                           [id](const Vehicle* v) { return v->getID() == id; });
    if (it != vehicles.end()) {
        delete *it;
        vehicles.erase(it);
        currentCount--;
    } else {
        std::cout << "Vehicle not in the lot" << std::endl;
    }
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    return std::count_if(vehicles.begin(), vehicles.end(),
                         [maxParkingDuration](const Vehicle* v) {
                             return v->getParkingDuration() > maxParkingDuration;
                         });
}

ParkingLot::~ParkingLot() {
    for (auto* vehicle : vehicles) {
        delete vehicle;
    }
}