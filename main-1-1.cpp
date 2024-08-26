#include "wizard.h"
#include "warrior.h"
#include <iostream>

int main() {
    Wizard wizard("Merlin", 100, 10, 50);
    Warrior warrior("Arthur", 120, 15, "Excalibur");

    while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
        wizard.castSpell(&warrior);
        if (warrior.getHealth() <= 0) break;

        warrior.swingWeapon(&wizard);
        if (wizard.getHealth() <= 0) break;
    }

    std::cout << "Battle over!\n";
    if (wizard.getHealth() <= 0) {
        std::cout << warrior.getName() << " wins!\n";
    } else {
        std::cout << wizard.getName() << " wins!\n";
    }

    return 0;
}