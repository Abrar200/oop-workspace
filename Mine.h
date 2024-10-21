#pragma once
#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity
{
public:
    Mine(int x, int y) : GameEntity(x, y, GameEntityType::MineType) {}

    Explosion explode()
    {
        setType(GameEntityType::NoneType);
        auto [x, y] = getPos();
        return Explosion(x, y);
    }
};