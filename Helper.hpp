#ifndef HELPER_HPP
#define HELPER_HPP

#include <tuple>
#include <cstdlib> // for abs()

class Helper {
public:
    static double absoluteSquaredDistance(std::tuple<int, int> item1, std::tuple<int, int> item2) {
        int x1 = std::get<0>(item1);
        int y1 = std::get<1>(item1);
        int x2 = std::get<0>(item2);
        int y2 = std::get<1>(item2);
        
        // Following the formula: (absolute(x2 - x1) + absolute(y2 - y1))²
        double diff = std::abs(x2 - x1) + std::abs(y2 - y1);
        return diff * diff;
    }
};

#endif
