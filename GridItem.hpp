#ifndef GRID_ITEM_HPP
#define GRID_ITEM_HPP

#include <tuple>

class GridItem
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    static int s_activeCount;

protected:
    void setDimensions(int width, int height)
    {
        m_width = width;
        m_height = height;
    }

public:
    // Default constructor
    GridItem() : m_x(0), m_y(0), m_width(0), m_height(0)
    {
        ++s_activeCount;
    }

    // Parameterized constructor
    GridItem(int x, int y, int width, int height) : GridItem()
    {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
    }

    // Virtual destructor
    virtual ~GridItem()
    {
        --s_activeCount;
    }

    // Set coordinates
    void setCoordinates(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    // Get coordinates
    std::tuple<int, int> getCoordinates()
    {
        return std::make_tuple(m_x, m_y);
    }

    // Get grid width
    int getGridWidth()
    {
        return m_width;
    }

    // Get grid height
    int getGridHeight()
    {
        return m_height;
    }

    // Get active count
    static int getActiveGridItemCount()
    {
        return s_activeCount;
    }
};

// Initialize static member
int GridItem::s_activeCount = 0;

#endif