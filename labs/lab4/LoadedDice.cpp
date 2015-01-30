#include <stdlib.h>
#include <time.h>
#include "LoadedDice.h"

LoadedDice::LoadedDice()
{
    numSides = 6;
    srand(time(NULL));
}

LoadedDice::LoadedDice(int numSides)
{
    this->numSides = numSides;
    srand(time(NULL));
}

int LoadedDice::rollDice() const
{
    if(rand() % 2)
    {
        return numSides;
    }
    else
    {
        return (rand() % numSides) + 1;
    }
}