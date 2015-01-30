#include <iostream>
#include <bits/stl_algo.h>
#include "Dice.h"
#include "LoadedDice.h"


int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}

int main()
{
    Dice die1;
    Dice die2;

    LoadedDice die3;
    LoadedDice die4;

    int unLoadedSim[100000];
    int loadedSim[100000];

    std::cout << "Non-loaded:" << std::endl;
    for(int i = 0; i < 100000; i++)
    {
        int result = rollTwoDice(die1, die2);
        std::cout << result << std::endl;

        unLoadedSim[i] = result;

    }

    std::cout << std::endl << "Loaded:" << std::endl;

    for(int i = 0; i < 100000; i++)
    {
        int result = rollTwoDice(die3, die4);
        std::cout << result << std::endl;

        loadedSim[i] = result;
    }

}