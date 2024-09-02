#include <iostream>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

int main() {
    House myHouse(3);

    Fridge* fridge = new Fridge(200, 250.0);
    TV* tv1 = new TV(150, 55.0);
    TV* tv2 = new TV(100, 32.0);

    myHouse.addAppliance(fridge);
    myHouse.addAppliance(tv1);
    myHouse.addAppliance(tv2);

    std::cout << "Total power consumption of the house: " 
              << myHouse.getTotalPowerConsumption() << std::endl;

    return 0;
}