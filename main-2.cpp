#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main()
{
    // Create a Ship and move it
    Ship ship(0, 0);
    std::cout << "Ship initial position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")" << std::endl;
    ship.move(2, 3);
    std::cout << "Ship position after move: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")" << std::endl;

    // Create a Mine and explode it
    Mine mine(5, 5);
    std::cout << "Mine initial type: " << static_cast<int>(mine.getType()) << std::endl;
    Explosion explosion = mine.explode();
    std::cout << "Mine type after explosion: " << static_cast<int>(mine.getType()) << std::endl;

    // Apply explosion effect to the ship
    std::cout << "Ship type before explosion: " << static_cast<int>(ship.getType()) << std::endl;
    explosion.apply(ship);
    std::cout << "Ship position after explosion: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")" << std::endl;
    std::cout << "Ship type after explosion: " << static_cast<int>(ship.getType()) << std::endl;

    return 0;
}