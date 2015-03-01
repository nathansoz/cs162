#include "Character.h"
#include "../SozLibs/Dice.h"
#include "Character.h"

#include <iostream>

void Character::AddKill()
{
    kills++;
}

void Character::Attack(Character *defender)
{
    int attackRoll = this->RollAttack();
    //std::cout << "Attacker rolls: " << attackRoll << std::endl;
    defender->Defend(attackRoll);
}

void Character::Defend(int attackRoll)
{
    int defendRoll = this->RollDefense();
    int damage = attackRoll - defendRoll - armor;

    //std::cout << "Defender rolls: " << defendRoll << std::endl;

    if(damage > 0)
    {
        currentStrengthPoints -= damage;

        if(currentStrengthPoints <= 0)
        {
            alive = false;
        }
    }

}

std::string Character::GetName()
{
    return name;
}

int Character::GetKills()
{
    return kills;
}

bool Character::IsAlive()
{
    return alive;
}

void Character::Reset()
{
    currentStrengthPoints = totalStrengthPoints;
    alive = true;
}

const int Character::RollAttack()
{
    int attack = 0;

    for(int i = 0; i < attackRolls; i++)
    {
        attack += attackDie->rollDie();
    }

    return attack;

}

const int Character::RollDefense()
{
    int defense = 0;

    for(int i = 0; i < defenceRolls; i++)
    {
        defense += defenseDie->rollDie();
    }

    return defense;
}

void Character::Regen()
{
    int addPoints = (rand() % 5) + 1;
    if(totalStrengthPoints < addPoints + currentStrengthPoints)
    {
        currentStrengthPoints = totalStrengthPoints;
    }
    else
    {
        currentStrengthPoints += addPoints;
    }
}

Character::~Character(){}

bool CompareCharacterKills::operator()(Character *char1, Character *char2)
{
    if(char1->GetKills() <= char2->GetKills())
        return true;
    else
        return false;
}

