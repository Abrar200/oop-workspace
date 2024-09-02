#include <iostream>
#include "Fridge.h"

int main() {
    Fridge fridge1;
    Fridge fridge2(200, 250.0);

    std::cout << "Fridge1 power rating: " << fridge1.get_powerRating() << std::endl;
    std::cout << "Fridge1 volume: " << fridge1.getVolume() << std::endl;
    std::cout << "Fridge1 power consumption: " << fridge1.getPowerConsumption() << std::endl;

    std::cout << "Fridge2 power rating: " << fridge2.get_powerRating() << std::endl;
    std::cout << "Fridge2 volume: " << fridge2.getVolume() << std::endl;
    std::cout << "Fridge2 power consumption: " << fridge2.getPowerConsumption() << std::endl;

    fridge1.set_powerRating(150);
    fridge1.setVolume(200.0);

    std::cout << "Updated Fridge1 power consumption: " << fridge1.getPowerConsumption() << std::endl;

    return 0;
}