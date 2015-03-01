#include "Goblin.h"

Goblin::Goblin()
{
    name = "Goblin";

    alive = true;
    attackDieSides = 6;
    attackRolls = 2;
    defenceDieSides = 6;
    defenceRolls = 1;

    armor = 3;
    totalStrengthPoints = 8;
    currentStrengthPoints = totalStrengthPoints;
    kills = 0;
    cutOpponentTendon = false;

    attackDie = new SozLibs::Dice(attackDieSides);
    defenseDie = new SozLibs::Dice(defenceDieSides);
}

Goblin::~Goblin()
{
    delete attackDie;
    delete defenseDie;
}

void Goblin::Attack(Character * defender)
{
    int attackRoll = this->RollAttack();

    if(attackRoll == 12 && defender->GetName() != "Goblin")
        cutOpponentTendon = true;

    defender->Defend(attackRoll);
}

void Goblin::Defend(int attackRoll)
{
    if(cutOpponentTendon)
    {
        attackRoll = (attackRoll / 2);
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

void Goblin::Reset()
{
    currentStrengthPoints = totalStrengthPoints;
    alive = true;
    cutOpponentTendon = false;
}

