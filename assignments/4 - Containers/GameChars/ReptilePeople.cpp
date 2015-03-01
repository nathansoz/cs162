#include "ReptilePeople.h"

ReptilePeople::ReptilePeople()
{
    name = "ReptilePeople";

    alive = true;
    attackDieSides = 6;
    attackRolls = 3;
    defenceDieSides = 6;
    defenceRolls = 1;

    armor = 7;
    totalStrengthPoints = 18;
    currentStrengthPoints = totalStrengthPoints;
    kills = 0;

    attackDie = new SozLibs::Dice(attackDieSides);
    defenseDie = new SozLibs::Dice(defenceDieSides);
}

ReptilePeople::~ReptilePeople()
{
    delete attackDie;
    delete defenseDie;
}