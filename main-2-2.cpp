#include <iostream>
#include "TV.h"

int main() {
    TV tv1;
    TV tv2(150, 55.0);

    std::cout << "TV1 power rating: " << tv1.get_powerRating() << std::endl;
    std::cout << "TV1 screen size: " << tv1.getScreenSize() << std::endl;
    std::cout << "TV1 power consumption: " << tv1.getPowerConsumption() << std::endl;

    std::cout << "TV2 power rating: " << tv2.get_powerRating() << std::endl;
    std::cout << "TV2 screen size: " << tv2.getScreenSize() << std::endl;
    std::cout << "TV2 power consumption: " << tv2.getPowerConsumption() << std::endl;

    tv1.set_powerRating(100);
    tv1.setScreenSize(42.0);

    std::cout << "Updated TV1 power consumption: " << tv1.getPowerConsumption() << std::endl;

    return 0;
}