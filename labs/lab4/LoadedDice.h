#pragma once

#include "Dice.h"

class LoadedDice : public Dice
{
public:
    LoadedDice();
    LoadedDice(int);
    int rollDice() const;
};