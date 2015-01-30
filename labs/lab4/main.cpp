#include <iostream>
#include <bits/stl_algo.h>
#include "Dice.h"
#include "LoadedDice.h"


int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}

double mean(int rolls[], int numRolls)
{
    double total = 0;
    for(int i = 0; i < numRolls; i++)
    {
        total += rolls[i];
    }

    return (static_cast<double>(total) / static_cast<double>(numRolls));
}

int main()
{
    Dice die1;
    Dice die2;

    LoadedDice die3;
    LoadedDice die4;

    int unLoadedSim[100000];
    int loadedSim[100000];

    std::cout << "Populating unloaded die:" << std::endl;
    for(int i = 0; i < 100000; i++)
    {
        int result = rollTwoDice(die1, die2);
        unLoadedSim[i] = result;

    }

    std::cout << std::endl << "Populating loaded die:" << std::endl;

    for(int i = 0; i < 100000; i++)
    {
        int result = rollTwoDice(die3, die4);
        loadedSim[i] = result;
    }

    std::cout << "Mean of unloaded: " << mean(unLoadedSim, 100000) << std::endl;
    std::cout << "Mean of loaded: " << mean(loadedSim, 100000) << std::endl;
}