#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "GridItem.hpp"
#include "Explorer.hpp"

enum InteractableType
{
    EXIT,
    PIT
};

class Interactable : public GridItem
{
private:
    static int s_activeInteractableCount;

public:
    Interactable() : GridItem()
    {
        ++s_activeInteractableCount;
    }

    Interactable(int x, int y, int width, int height)
        : GridItem(x, y, width, height)
    {
        ++s_activeInteractableCount;
    }

    virtual ~Interactable()
    {
        --s_activeInteractableCount;
    }

    static int getActiveInteractableCount()
    {
        return s_activeInteractableCount;
    }

    virtual bool interact(Explorer *player) = 0;
    virtual InteractableType getType() = 0;
};

int Interactable::s_activeInteractableCount = 0;

#endif