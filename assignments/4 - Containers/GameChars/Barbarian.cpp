#include "Barbarian.h"

Barbarian::Barbarian()
{
    name = "Barbarian";

    alive = true;
    attackDieSides = 6;
    attackRolls = 2;
    defenceDieSides = 6;
    defenceRolls = 2;

    armor = 0;
    totalStrengthPoints = 12;
    currentStrengthPoints = totalStrengthPoints;

    attackDie = new SozLibs::Dice(attackDieSides);
    defenseDie = new SozLibs::Dice(defenceDieSides);
}

Barbarian::~Barbarian()
{
    delete attackDie;
    delete defenseDie;
}