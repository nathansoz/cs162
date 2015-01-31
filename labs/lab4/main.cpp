#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "Dice.h"
#include "LoadedDice.h"
#include "SozLibs/Stats.h"


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

    std::vector<int> unloadedSim;
    std::vector<int> loadedSim;

    std::cout << "Populating unloaded die:" << std::endl;
    for(int i = 0; i < 1000000; i++)
    {
        int result = rollTwoDice(die1, die2);
        unloadedSim.push_back(result);

    }

    std::cout << std::endl << "Populating loaded die:" << std::endl;

    for(int i = 0; i < 1000000; i++)
    {
        int result = rollTwoDice(die3, die4);
        loadedSim.push_back(result);
    }

    std::cout << "Mean of unloaded: " << SozLibs::Stats::Mean(unloadedSim) << std::endl;
    std::cout << "Mean of loaded: " << SozLibs::Stats::Mean(loadedSim) << std::endl;

    //median

    std::cout << "Median of unloaded: " << SozLibs::Stats::Median(unloadedSim) << std::endl;
    std::cout << "Median of loaded: " << SozLibs::Stats::Median(loadedSim) << std::endl;

    //mode of unloaded dice
    std::vector<int> unloadedMode = SozLibs::Stats::Mode(unloadedSim);
    std::cout << "Mode(s) of unloaded: ";
    for(int i = 0; i < unloadedMode.size(); i++)
    {
        std::cout << unloadedMode.at(i) << " ";
    }
    std::cout << std::endl;

    //mode of loaded dice
    std::vector<int> loadedMode = SozLibs::Stats::Mode(loadedSim);
    std::cout << "Mode(s) of loaded: ";
    for(int i = 0; i < loadedMode.size(); i++)
    {
        std::cout << loadedMode.at(i) << " ";
    }
    std::cout << std::endl;

    //standard Deviation
    std::cout << "Standard Deviation of unloaded: " << SozLibs::Stats::StdDev(unloadedSim) << std::endl;
    std::cout << "Standard Deviation of loaded: " << SozLibs::Stats::StdDev(loadedSim) << std::endl;
}