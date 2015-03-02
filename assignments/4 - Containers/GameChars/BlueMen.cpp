#include "BlueMen.h"

BlueMen::BlueMen(std::string displayName)
{
    name = "BlueMen";
    this->displayName = displayName;

    alive = true;
    attackDieSides = 10;
    attackRolls = 2;
    defenceDieSides = 6;
    defenceRolls = 3;

    armor = 3;
    totalStrengthPoints = 12;
    currentStrengthPoints = totalStrengthPoints;
    kills = 0;

    attackDie = new SozLibs::Dice(attackDieSides);
    defenseDie = new SozLibs::Dice(defenceDieSides);
}

BlueMen::~BlueMen()
{
    delete attackDie;
    delete defenseDie;
}