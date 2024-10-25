#ifndef EXPLORER_HPP
#define EXPLORER_HPP

#include "GridItem.hpp"

class Explorer : public GridItem
{
private:
    int m_stamina;

public:
    Explorer(int gridWidth, int gridHeight) : GridItem(0, 0, gridWidth, gridHeight), m_stamina(2) {}

    int getStamina() { return m_stamina; }

    void jumpPit()
    {
        if (m_stamina > 0)
        {
            m_stamina--;
        }
    }

    bool move(int xOffset, int yOffset)
    {
        // Check if move is diagonal (illegal)
        if (xOffset != 0 && yOffset != 0)
        {
            return false;
        }

        auto [currentX, currentY] = getCoordinates();
        int newX = currentX + xOffset;
        int newY = currentY + yOffset;

        // Check if new position is within grid bounds
        if (newX >= 0 && newX < getGridWidth() &&
            newY >= 0 && newY < getGridHeight())
        {
            setCoordinates(newX, newY);
            return true;
        }
        return false;
    }
};

#endif