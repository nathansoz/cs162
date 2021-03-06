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
    cutOpponentTendon = false;

    attackDie = new Dice(attackDieSides);
    defenseDie = new Dice(defenceDieSides);
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

