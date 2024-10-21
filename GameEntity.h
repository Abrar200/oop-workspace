#pragma once
#include <tuple>

enum class GameEntityType
{
    ExplosionType,
    MineType,
    NoneType,
    ShipType
};

class GameEntity
{
private:
    std::tuple<int, int> position;
    GameEntityType type;

public:
    GameEntity(int x, int y, GameEntityType type) : position(x, y), type(type) {}

    std::tuple<int, int> getPos() const { return position; }
    GameEntityType getType() const { return type; }

    void setPos(int x, int y) { position = std::make_tuple(x, y); }
    void setType(GameEntityType newType) { type = newType; }
};