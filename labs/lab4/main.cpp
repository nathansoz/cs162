#include <iostream>
#include <bits/stl_algo.h>
#include <vector>
#include "Dice.h"
#include "LoadedDice.h"


int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}

double mean(std::vector<int> &rolls)
{
    double total = 0;
    for(int i = 0; i < rolls.size(); i++)
    {
        total += rolls[i];
    }

    return (static_cast<double>(total) / static_cast<double>(rolls.size()));
}

double median(std::vector<int> &inputValues)
{
    std::sort(inputValues.begin(), inputValues.end());

    int median = -1;

    if(inputValues.size() % 2 == 0)
    {
        //even case
        //we can use an integer division trick to get to the middle

        int middlePositionA = (inputValues.size() / 2);
        int middlePositionB = ((inputValues.size() /2) - 1);


        median = ((inputValues.at(middlePositionA) + inputValues.at(middlePositionB)) / 2);

    }
    else
    {
        //odd case
        int middlePosition = (inputValues.size() / 2);
        median = inputValues.at(middlePosition);
    }

    return median;
}

//I took this mode function that I wrote last quarter from
// https://raw.githubusercontent.com/nathansoz/cs161/master/week8/findMode.cpp
std::vector<int> mode(std::vector<int> &inputValues)
{
    int count = 0;
    int maxNum = 0;
    int currentNumber = inputValues.at(0);

    //we need a sorted array to keep track of arbitrary values
    //the only other way that I could think to keep track of this would be a
    //huge array that we use as a counter.
    std::sort(inputValues.begin(), inputValues.end());

    std::vector<int> modes;

    for(int i = 0; i < inputValues.size(); i++)
    {

        if(currentNumber == inputValues.at(i))
        {
            count++;

            if(count > maxNum)
            {
                //This pushes the maxnum to be a greater number if need be...
                maxNum = count;
            }
        }
        else
        {
            if(count > maxNum)
            {
                maxNum = count;
            }
            currentNumber = inputValues.at(i);
            count = 1;
        }
    }

    count = 0;
    currentNumber = inputValues.at(0);

    //This is where we actually place values in our modes array
    for(int i = 0; i < inputValues.size(); i++)
    {
        if(currentNumber == inputValues.at(i))
        {
            count++;
            if(count == maxNum)
            {
                modes.push_back(currentNumber);
            }
        }
        else
        {
            currentNumber = inputValues.at(i);
            count = 1;

            //Handle maxNum of 1
            if(count == maxNum)
            {
                modes.push_back(currentNumber);
            }
        }
    }

    return modes;
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

    std::cout << "Mean of unloaded: " << mean(unloadedSim) << std::endl;
    std::cout << "Mean of loaded: " << mean(loadedSim) << std::endl;

    //median

    std::cout << "Median of unloaded: " << median(unloadedSim) << std::endl;
    std::cout << "Median of loaded: " << median(loadedSim) << std::endl;

    //mode of unloaded dice
    std::vector<int> unloadedMode = mode(unloadedSim);
    std::cout << "Mode(s) of unloaded: ";
    for(int i = 0; i < unloadedMode.size(); i++)
    {
        std::cout << unloadedMode.at(i) << " ";
    }
    std::cout << std::endl;

    //mode of loaded dice
    std::vector<int> loadedMode = mode(loadedSim);
    std::cout << "Mode(s) of loaded: ";
    for(int i = 0; i < loadedMode.size(); i++)
    {
        std::cout << loadedMode.at(i) << " ";
    }
    std::cout << std::endl;
}