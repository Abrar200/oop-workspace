#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numVehicles;
    std::cout << "Enter the number of vehicles to park: ";
    std::cin >> numVehicles;

    std::vector<Vehicle*> vehicles;

    for (int i = 0; i < numVehicles; ++i) {
        std::string vehicleType;
        std::cout << "Enter vehicle type (Car/Bus/Motorbike): ";
        std::cin >> vehicleType;

        Vehicle* vehicle;
        if (vehicleType == "Car") {
            vehicle = new Car(i);
        } else if (vehicleType == "Bus") {
            vehicle = new Bus(i);
        } else if (vehicleType == "Motorbike") {
            vehicle = new Motorbike(i);
        } else {
            std::cout << "Invalid vehicle type. Skipping." << std::endl;
            continue;
        }

        vehicles.push_back(vehicle);
    }

    for (const auto* vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getID() 
                  << ", Parking Duration: " << vehicle->getParkingDuration() << " seconds" << std::endl;
    }

    for (auto* vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}