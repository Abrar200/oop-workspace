#include <iostream>
#include "Game.h"

int main()
{
    Game game;

    int numShips = 5;
    int numMines = 10;
    int gridWidth = 20;
    int gridHeight = 20;
    int maxIterations = 100;
    double mineDistanceThreshold = 1.5;

    auto entities = game.initGame(numShips, numMines, gridWidth, gridHeight);

    std::cout << "Initial game state:" << std::endl;
    std::cout << "Number of entities: " << entities.size() << std::endl;

    for (const auto *entity : entities)
    {
        auto [x, y] = entity->getPos();
        std::cout << "Entity at (" << x << ", " << y << ") of type " << static_cast<int>(entity->getType()) << std::endl;
    }

    std::cout << "\nStarting game loop..." << std::endl;
    game.gameLoop(maxIterations, mineDistanceThreshold);

    std::cout << "\nFinal game state:" << std::endl;
    entities = game.get_entities();
    std::cout << "Number of remaining entities: " << entities.size() << std::endl;

    for (const auto *entity : entities)
    {
        auto [x, y] = entity->getPos();
        std::cout << "Entity at (" << x << ", " << y << ") of type " << static_cast<int>(entity->getType()) << std::endl;
    }

    return 0;
}