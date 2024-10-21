#pragma once
#include <vector>
#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game
{
private:
    std::vector<GameEntity *> entities;

public:
    std::vector<GameEntity *> get_entities() const { return entities; }
    void set_entities(const std::vector<GameEntity *> &new_entities) { entities = new_entities; }

    std::vector<GameEntity *> initGame(int numShips, int numMines, int gridWidth, int gridHeight)
    {
        entities.clear();

        for (int i = 0; i < numShips; ++i)
        {
            auto [x, y] = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(x, y));
        }

        for (int i = 0; i < numMines; ++i)
        {
            auto [x, y] = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(x, y));
        }

        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold)
    {
        for (int iteration = 0; iteration < maxIterations; ++iteration)
        {
            // Move all ships
            for (auto *entity : entities)
            {
                if (entity->getType() == GameEntityType::ShipType)
                {
                    static_cast<Ship *>(entity)->move(1, 0);
                }
            }

            // Check for collisions and explode mines
            for (auto it = entities.begin(); it != entities.end();)
            {
                if ((*it)->getType() == GameEntityType::ShipType)
                {
                    for (auto *potential_mine : entities)
                    {
                        if (potential_mine->getType() == GameEntityType::MineType)
                        {
                            if (Utils::calculateDistance((*it)->getPos(), potential_mine->getPos()) <= mineDistanceThreshold)
                            {
                                Explosion explosion = static_cast<Mine *>(potential_mine)->explode();
                                explosion.apply(**it);
                                break;
                            }
                        }
                    }
                }

                if ((*it)->getType() == GameEntityType::NoneType)
                {
                    delete *it;
                    it = entities.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            // Check if all ships are destroyed
            bool shipsRemain = false;
            for (auto *entity : entities)
            {
                if (entity->getType() == GameEntityType::ShipType)
                {
                    shipsRemain = true;
                    break;
                }
            }

            if (!shipsRemain)
            {
                std::cout << "All ships destroyed. Game over at iteration " << iteration << std::endl;
                break;
            }
        }
    }

    ~Game()
    {
        for (auto *entity : entities)
        {
            delete entity;
        }
    }
};