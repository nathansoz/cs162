#pragma once

#include "Character.h"

class Shadow : public Character
{
public:
    Shadow();
    ~Shadow();

    virtual void Defend(int attackRoll);
};