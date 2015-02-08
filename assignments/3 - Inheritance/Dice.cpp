#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include "Dice.h"

Dice::Dice(int numSides)
{
    this->numSides = numSides;
}

int Dice::rollDie() const
{
    return (rand() % numSides) + 1;
}