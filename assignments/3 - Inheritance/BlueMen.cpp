#include "BlueMen.h"

BlueMen::BlueMen()
{
    name = "BlueMen";

    alive = true;
    attackDieSides = 10;
    attackRolls = 2;
    defenceDieSides = 6;
    defenceRolls = 3;

    armor = 3;
    totalStrengthPoints = 12;
    currentStrengthPoints = totalStrengthPoints;

    attackDie = new Dice(attackDieSides);
    defenseDie = new Dice(defenceDieSides);
}

BlueMen::~BlueMen()
{
    delete attackDie;
    delete defenseDie;
}