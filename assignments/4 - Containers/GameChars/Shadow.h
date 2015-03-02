#pragma once

#include "Character.h"

class Shadow : public Character
{
public:
    Shadow(std::string displayName);
    ~Shadow();

    virtual void Defend(int attackRoll);
};