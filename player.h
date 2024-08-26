#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int health;
    int damage;

public:
    Player(std::string name, int health, int damage);
    
    virtual void attack(Player* opponent, int damage);
    void takeDamage(int damage);
    
    std::string getName() const;
    void setName(const std::string& name);
    int getHealth() const;
    void setHealth(int health);
    int getDamage() const;
    void setDamage(int damage);
};

#endif