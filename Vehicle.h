#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>

class Vehicle {
private:
    std::time_t timeOfEntry;
    int id;

public:
    Vehicle(int vehicleId);
    int getID() const;
    virtual int getParkingDuration() const;
    virtual ~Vehicle() = default;
};

#endif