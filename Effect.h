#pragma once
#include "GameEntity.h"

class Effect
{
public:
    virtual void apply(GameEntity &entity) = 0;
    virtual ~Effect() = default;
};