#include <algorithm>
#include <cmath>
#include "Stats.h"


SozLibs::Stats::Stats()
{
}

double SozLibs::Stats::Mean(std::vector<int> &inputValues)
{
    double total = 0;
    for(int i = 0; i < inputValues.size(); i++)
    {
        total += inputValues.at(i);
    }

    return (static_cast<double>(total) / static_cast<double>(inputValues.size()));
}

double SozLibs::Stats::Median(std::vector<int> &inputValues)
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
std::vector<int> SozLibs::Stats::Mode(std::vector<int> &inputValues)
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

double SozLibs::Stats::StdDev(std::vector<int> &inputValues)
{
    double meanOfInput = SozLibs::Stats::Mean(inputValues);
    double additionOfSquares = 0;

    for(int i = 0; i < inputValues.size(); i++)
    {
        additionOfSquares += std::pow((inputValues.at(i) - meanOfInput), 2);
    }

    return std::sqrt((additionOfSquares / static_cast<double>(inputValues.size())));
}
