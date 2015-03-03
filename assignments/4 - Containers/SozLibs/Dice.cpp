#include <stdlib.h>
#include "Dice.h"

SozLibs::Dice::Dice(int numSides)
{
    this->numSides = numSides;
}

int SozLibs::Dice::rollDie() const
{
    return (rand() % numSides) + 1;
}