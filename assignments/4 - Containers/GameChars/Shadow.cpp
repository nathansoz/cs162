#include <iostream>
#include "Shadow.h"

Shadow::Shadow(std::string displayName)
{
    name = "Shadow";
    this->displayName = displayName;

    alive = true;
    attackDieSides = 10;
    attackRolls = 2;
    defenceDieSides = 6;
    defenceRolls = 1;

    armor = 0;
    totalStrengthPoints = 12;
    currentStrengthPoints = totalStrengthPoints;
    kills = 0;

    attackDie = new SozLibs::Dice(attackDieSides);
    defenseDie = new SozLibs::Dice(defenceDieSides);
}

Shadow::~Shadow()
{
    delete attackDie;
    delete defenseDie;
}

void Shadow::Defend(int attackRoll)
{
    //calculate 50/50 chance
    if((rand() % 2) == 0)
    {
        return;
    }

    int defendRoll = this->RollDefense();
    int damage = attackRoll - defendRoll - armor;

    if(damage > 0)
    {
        currentStrengthPoints -= damage;

        if(currentStrengthPoints <= 0)
        {
            alive = false;
        }
    }
}

