#ifndef PIT_HPP
#define PIT_HPP

#include "Interactable.hpp"
#include "Helper.hpp"

class Pit : public Interactable
{
private:
    bool m_covered;

public:
    Pit(int x, int y, int width, int height)
        : Interactable(x, y, width, height), m_covered(false) {}

    bool interact(Explorer *player) override
    {
        if (!m_covered &&
            Helper::absoluteSquaredDistance(getCoordinates(), player->getCoordinates()) == 0)
        {
            player->jumpPit();
            m_covered = true;
            return player->getStamina() == 0;
        }
        return false;
    }

    InteractableType getType() override
    {
        return InteractableType::PIT;
    }
};

#endif