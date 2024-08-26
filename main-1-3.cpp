#include <iostream>
#include <thread>
#include <chrono>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10);

    for (int i = 0; i < 5; ++i) {
        parkingLot.parkVehicle(new Car(i));
    }

    for (int i = 5; i < 8; ++i) {
        parkingLot.parkVehicle(new Bus(i));
    }

    for (int i = 8; i < 10; ++i) {
        parkingLot.parkVehicle(new Motorbike(i));
    }

    std::this_thread::sleep_for(std::chrono::seconds(20));

    int overstayingCount = parkingLot.countOverstayingVehicles(15);
    std::cout << "Number of vehicles overstaying 15 seconds: " << overstayingCount << std::endl;

    return 0;
}