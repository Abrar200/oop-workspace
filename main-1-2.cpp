#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10);

    while (parkingLot.getCount() < 10) {
        std::string vehicleType;
        std::cout << "Enter vehicle type to park (Car/Bus/Motorbike): ";
        std::cin >> vehicleType;

        Vehicle* vehicle;
        if (vehicleType == "Car") {
            vehicle = new Car(parkingLot.getCount());
        } else if (vehicleType == "Bus") {
            vehicle = new Bus(parkingLot.getCount());
        } else if (vehicleType == "Motorbike") {
            vehicle = new Motorbike(parkingLot.getCount());
        } else {
            std::cout << "Invalid vehicle type. Try again." << std::endl;
            continue;
        }

        parkingLot.parkVehicle(vehicle);
        std::cout << "Vehicle parked. Current count: " << parkingLot.getCount() << std::endl;
    }

    int idToUnpark;
    std::cout << "Enter the ID of the vehicle to unpark: ";
    std::cin >> idToUnpark;
    parkingLot.unparkVehicle(idToUnpark);

    return 0;
}