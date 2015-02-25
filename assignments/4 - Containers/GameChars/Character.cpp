#include "Character.h"
#include "../SozLibs/Dice.h"

#include <iostream>

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