#pragma once

#include "Character.h"

class Goblin : public Character
{
private:
    bool cutOpponentTendon;
public:
    Goblin(std::string displayName);
    ~Goblin();

    virtual void Attack(Character*);
    virtual void Defend(int attackRoll);
    virtual void Reset();
};

