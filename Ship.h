#pragma once
#include "GameEntity.h"

class Ship : public GameEntity
{
public:
    Ship(int x, int y) : GameEntity(x, y, GameEntityType::ShipType) {}

    void move(int dx, int dy)
    {
        auto [x, y] = getPos();
        setPos(x + dx, y + dy);
    }
};