#pragma once

#import "Dice.h"

class LoadedDice : public Dice
{
public:
    LoadedDice();
    LoadedDice(int);
    int rollDice() const;
};