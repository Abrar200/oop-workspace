#ifndef EQUIVALENCE_TESTS_H
#define EQUIVALENCE_TESTS_H

#include <iostream>
#include <limits>
#include "Addition.h"

class EquivalenceTests
{
public:
    void runTests()
    {
        testPositiveIntegers();
        testNegativeIntegers();
        testMixedIntegers();
        testZeroes();
        testBigNumbers();
        testSpecialCases();
    }

private:
    Addition addition;

    void testPositiveIntegers()
    {
        if (addition.add(5, 10) != 15)
        {
            std::cout << "Test Positive Integers failed: 5 + 10 should equal 15" << std::endl;
        }
        else
        {
            std::cout << "Test Positive Integers passed" << std::endl;
        }
    }

    void testNegativeIntegers()
    {
        if (addition.add(-4, -5) != -9)
        {
            std::cout << "Test Negative Integers failed: -4 + (-5) should equal -9" << std::endl;
        }
        else
        {
            std::cout << "Test Negative Integers passed" << std::endl;
        }
    }

    void testMixedIntegers()
    {
        if (addition.add(-7, 3) != -4)
        {
            std::cout << "Test Mixed Integers failed: -7 + 3 should equal -4" << std::endl;
        }
        else
        {
            std::cout << "Test Mixed Integers passed" << std::endl;
        }
    }

    void testZeroes()
    {
        if (addition.add(0, 0) != 0)
        {
            std::cout << "Test Zeroes failed: 0 + 0 should equal 0" << std::endl;
        }
        else
        {
            std::cout << "Test Zeroes passed" << std::endl;
        }
    }

    void testBigNumbers()
    {
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();

        if (addition.add(max, 1) != min)
        {
            std::cout << "Test Big Positive Numbers passed: detected overflow" << std::endl;
        }
        else
        {
            std::cout << "Test Big Positive Numbers failed: did not detect overflow" << std::endl;
        }

        if (addition.add(min, -1) != max)
        {
            std::cout << "Test Big Negative Numbers passed: detected underflow" << std::endl;
        }
        else
        {
            std::cout << "Test Big Negative Numbers failed: did not detect underflow" << std::endl;
        }
    }

    void testSpecialCases()
    {
        if (addition.add(1, 0) != 1)
        {
            std::cout << "Test Special Case 1 failed: 1 + 0 should equal 1" << std::endl;
        }
        else
        {
            std::cout << "Test Special Case 1 passed" << std::endl;
        }

        if (addition.add(-1, 0) != -1)
        {
            std::cout << "Test Special Case -1 failed: -1 + 0 should equal -1" << std::endl;
        }
        else
        {
            std::cout << "Test Special Case -1 passed" << std::endl;
        }
    }
};

#endif