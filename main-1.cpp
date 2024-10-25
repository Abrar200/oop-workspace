#include <iostream>
#include "GridItem.hpp"
#include "Helper.hpp"

void testGridItem()
{
    std::cout << "Testing GridItem class..." << std::endl;

    // Test default constructor and active count
    GridItem item1;
    std::cout << "Active count after creating item1: " << GridItem::getActiveGridItemCount() << std::endl;

    // Test parameterized constructor
    GridItem item2(1, 2, 4, 3);
    std::cout << "Active count after creating item2: " << GridItem::getActiveGridItemCount() << std::endl;

    // Test coordinates
    auto [x, y] = item2.getCoordinates();
    std::cout << "Item2 coordinates: (" << x << "," << y << ")" << std::endl;

    // Test dimensions
    std::cout << "Item2 dimensions: " << item2.getGridWidth() << "x" << item2.getGridHeight() << std::endl;

    // Test setCoordinates
    item1.setCoordinates(3, 4);
    auto [newX, newY] = item1.getCoordinates();
    std::cout << "Item1 new coordinates: (" << newX << "," << newY << ")" << std::endl;
}

void testHelper()
{
    std::cout << "\nTesting Helper class..." << std::endl;

    // Test absoluteSquaredDistance
    auto point1 = std::make_tuple(0, 0);
    auto point2 = std::make_tuple(3, 4);
    double distance = Helper::absoluteSquaredDistance(point1, point2);
    std::cout << "Squared distance between (0,0) and (3,4): " << distance << std::endl;
}

int main()
{
    testGridItem();
    testHelper();

    std::cout << "\nFinal active count: " << GridItem::getActiveGridItemCount() << std::endl;
    return 0;
}