#pragma once

#include "Dice.h"

#include <string>

class Character
{

protected:
    std::string name;

    int attackRolls;
    int attackDieSides;
    int defenceRolls;
    int defenceDieSides;
    int armor;

    Dice *attackDie;
    Dice *defenseDie;

    int totalStrengthPoints;
    int currentStrengthPoints;
    bool alive;

    virtual const int RollAttack();
    virtual const int RollDefense();

public:

    virtual void Attack(Character*);
    virtual void Defend(int attackRoll);
    virtual void Reset();

    virtual std::string GetName();
    int GetStrengthPoints;
    bool IsAlive();


};