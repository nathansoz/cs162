#include "Barbarian.h"
#include "Dice.h"

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

    attackDie = new Dice(attackDieSides);
    defenseDie = new Dice(defenceDieSides);
}

Barbarian::~Barbarian()
{
    delete attackDie;
    delete defenseDie;
}