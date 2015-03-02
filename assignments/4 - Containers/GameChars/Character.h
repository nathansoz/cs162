#pragma once

#include "../SozLibs/Dice.h"

#include <string>

class Character
{

protected:
    std::string name;
    std::string displayName;

    int attackRolls;
    int attackDieSides;
    int defenceRolls;
    int defenceDieSides;
    int armor;

    SozLibs::Dice *attackDie;
    SozLibs::Dice *defenseDie;

    int totalStrengthPoints;
    int currentStrengthPoints;
    bool alive;
    int kills;

    virtual const int RollAttack();
    virtual const int RollDefense();

public:

    virtual void Attack(Character*);
    virtual void Defend(int attackRoll);
    virtual void Reset();

    void Regen();

    virtual std::string GetName();
    std::string GetDisplayName();
    bool IsAlive();
    void AddKill();
    int GetKills();

    virtual ~Character();



};

class CompareCharacterKills
{
public:
    bool operator()(Character* char1, Character* char2);
};

