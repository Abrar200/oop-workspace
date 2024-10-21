#pragma once
#include <tuple>
#include <random>
#include <cmath>

class Utils
{
public:
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> distX(0, gridWidth - 1);
        std::uniform_int_distribution<> distY(0, gridHeight - 1);
        return std::make_tuple(distX(gen), distY(gen));
    }

    static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2)
    {
        int dx = std::get<0>(pos1) - std::get<0>(pos2);
        int dy = std::get<1>(pos1) - std::get<1>(pos2);
        return std::sqrt(dx * dx + dy * dy);
    }
};