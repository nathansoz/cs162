#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "Dice.h"
#include "LoadedDice.h"
#include "SozLibs/Stats.h"

//controls the number of simulations that each dice pair gets
const int NUM_SIM = 1000000;

int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}

void diceSim(const Dice& die1, const Dice& die2, std::vector<int>& results, int numRolls)
{
    for(int i = 0; i < numRolls; i++)
    {
        int result = rollTwoDice(die1, die2);
        results.push_back(result);

    }
}

void printStats(std::vector<int>& stats)
{
    std::cout << "Mean: " << SozLibs::Stats::Mean(stats) << std::endl;

    //median

    std::cout << "Median: " << SozLibs::Stats::Median(stats) << std::endl;

    //mode of unloaded dice
    std::vector<int> unloadedMode = SozLibs::Stats::Mode(stats);
    std::cout << "Mode: ";
    for(int i = 0; i < unloadedMode.size(); i++)
    {
        std::cout << unloadedMode.at(i) << " ";
    }
    std::cout << std::endl;

    //standard Deviation
    std::cout << "Standard Deviation: " << SozLibs::Stats::StdDev(stats) << std::endl << std::endl;

}

int main()
{
    //standard 6 sided dice
    Dice die1;
    Dice die2;
    LoadedDice die3;
    LoadedDice die4;

    //20 sided dice
    Dice die5(20);
    Dice die6(20);
    LoadedDice die7(20);
    LoadedDice die8(20);


    std::vector<int> unloadedSimSix;
    std::vector<int> loadedSimSix;
    std::vector<int> unloadedSimTwenty;
    std::vector<int> loadedSimTwenty;

    std::cout << "Populating unloaded and loaded 6 sided dice rolls..." << std::endl << std::endl;

    diceSim(die1, die2, unloadedSimSix, NUM_SIM);
    diceSim(die3, die4, loadedSimSix, NUM_SIM);

    //long running function calls
    std::cout << "Unloaded, six sided dice stats: " << std::endl;
    printStats(unloadedSimSix);
    std::cout << "Loaded, six sided dice stats: " << std::endl;
    printStats(loadedSimSix);

    std::cout << "Populating unloaded and loaded 20 sided dice rolls..." << std::endl << std::endl;

    diceSim(die5, die6, unloadedSimTwenty, NUM_SIM);
    diceSim(die7, die8, loadedSimTwenty, NUM_SIM);

    std::cout << "Unloaded, twenty sided dice stats: " << std::endl;
    printStats(unloadedSimTwenty);
    std::cout << "Loaded, twenty sided dice stats: " << std::endl;
    printStats(loadedSimTwenty);


}