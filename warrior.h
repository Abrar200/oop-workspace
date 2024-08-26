#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"

class Warrior : public Player {
private:
    std::string weapon;

public:
    Warrior(std::string name, int health, int damage, std::string weapon);
    
    void swingWeapon(Player* opponent);
    
    std::string getWeapon() const;
    void setWeapon(const std::string& weapon);
};

#endif