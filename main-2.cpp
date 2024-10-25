#include <iostream>
#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"

void printStatus(Explorer *explorer)
{
    auto [x, y] = explorer->getCoordinates();
    std::cout << "Explorer position: (" << x << "," << y
              << "), Stamina: " << explorer->getStamina() << std::endl;
}

int main()
{
    // Create a 4x3 grid game
    Explorer player(4, 3);
    Exit exit(4, 3);
    Pit pit1(2, 1, 4, 3);
    Pit pit2(1, 1, 4, 3);

    std::cout << "Initial state:" << std::endl;
    std::cout << "Active GridItems: " << GridItem::getActiveGridItemCount() << std::endl;
    std::cout << "Active Interactables: " << Interactable::getActiveInteractableCount() << std::endl;
    printStatus(&player);

    // Test movement
    std::cout << "\nTesting movement:" << std::endl;
    std::cout << "Move right (1,0): " << (player.move(1, 0) ? "Success" : "Failed") << std::endl;
    printStatus(&player);

    // Test diagonal movement (should fail)
    std::cout << "Move diagonal (1,1): " << (player.move(1, 1) ? "Success" : "Failed") << std::endl;
    printStatus(&player);

    // Test pit interaction
    std::cout << "\nTesting pit interaction:" << std::endl;
    player.move(1, 1); // Move to pit1
    bool died = pit1.interact(&player);
    std::cout << "Interacted with pit1, died: " << (died ? "Yes" : "No") << std::endl;
    printStatus(&player);

    // Test exit interaction
    std::cout << "\nTesting exit interaction:" << std::endl;
    player.move(1, 0); // Move towards exit
    bool reached_exit = exit.interact(&player);
    std::cout << "Reached exit: " << (reached_exit ? "Yes" : "No") << std::endl;

    return 0;
}