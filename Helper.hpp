#ifndef HELPER_HPP
#define HELPER_HPP

#include <tuple>
#include <cmath>

class Helper {
public:
    static double absoluteSquaredDistance(std::tuple<int, int> item1, std::tuple<int, int> item2) {
        int x1 = std::get<0>(item1);
        int y1 = std::get<1>(item1);
        int x2 = std::get<0>(item2);
        int y2 = std::get<1>(item2);
        
        // Calculate absolute squared distance without using pow
        // The formula is (x2-x1)² + (y2-y1)²
        int dx = x2 - x1;
        int dy = y2 - y1;
        return dx * dx + dy * dy;
    }
};

#endif
