#include <iostream>
#include "Appliance.h"

int main() {
    Appliance app1;
    Appliance app2(1000);

    std::cout << "App1 power rating: " << app1.get_powerRating() << std::endl;
    std::cout << "App2 power rating: " << app2.get_powerRating() << std::endl;

    app1.turnOn();
    app2.turnOff();

    std::cout << "App1 is on: " << (app1.get_isOn() ? "Yes" : "No") << std::endl;
    std::cout << "App2 is on: " << (app2.get_isOn() ? "Yes" : "No") << std::endl;

    std::cout << "App1 power consumption: " << app1.getPowerConsumption() << std::endl;
    std::cout << "App2 power consumption: " << app2.getPowerConsumption() << std::endl;

    return 0;
}