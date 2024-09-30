#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include "Addition.h"

class UnitTest
{
public:
    void runTests()
    {
        testAddition();
    }

private:
    void testAddition()
    {
        Addition addition;

        if (addition.add(1, 2) != 3)
        {
            std::cout << "Test 1 failed: 1 + 2 should equal 3" << std::endl;
        }
        else
        {
            std::cout << "Test 1 passed" << std::endl;
        }

        if (addition.add(5, 0) != 5)
        {
            std::cout << "Test 2 failed: 5 + 0 should equal 5" << std::endl;
        }
        else
        {
            std::cout << "Test 2 passed" << std::endl;
        }

        if (addition.add(-3, 7) != 4)
        {
            std::cout << "Test 3 failed: -3 + 7 should equal 4" << std::endl;
        }
        else
        {
            std::cout << "Test 3 passed" << std::endl;
        }
    }
};

#endif