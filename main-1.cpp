#include <iostream>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"

int main()
{
    const int gridWidth = 10;
    const int gridHeight = 10;

    // Generate some random positions
    auto pos1 = Utils::generateRandomPos(gridWidth, gridHeight);
    auto pos2 = Utils::generateRandomPos(gridWidth, gridHeight);
    auto pos3 = Utils::generateRandomPos(gridWidth, gridHeight);

    std::cout << "Random positions:" << std::endl;
    std::cout << "Pos1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")" << std::endl;
    std::cout << "Pos2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")" << std::endl;
    std::cout << "Pos3: (" << std::get<0>(pos3) << ", " << std::get<1>(pos3) << ")" << std::endl;

    // Calculate distances
    double dist12 = Utils::calculateDistance(pos1, pos2);
    double dist23 = Utils::calculateDistance(pos2, pos3);
    double dist31 = Utils::calculateDistance(pos3, pos1);

    std::cout << "\nDistances:" << std::endl;
    std::cout << "Distance between Pos1 and Pos2: " << dist12 << std::endl;
    std::cout << "Distance between Pos2 and Pos3: " << dist23 << std::endl;
    std::cout << "Distance between Pos3 and Pos1: " << dist31 << std::endl;

    return 0;
}