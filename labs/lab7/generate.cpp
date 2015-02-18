#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

void FillFile(std::ofstream &outFile, int numGenerations)
{
    //Adapted from this example of c++11 random number generation:
    //  http://www.guyrutenberg.com/2014/05/03/c-mt19937-example/

    std::mt19937_64 randomNum(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1, 9);

    if(outFile)
    {
        for(int i = 0; i < numGenerations; i++)
        {
            outFile << distribution(randomNum);
        }
    }
    else
    {

    }

}

int main()
{
    std::ofstream test;
    test.open("blah.txt");

    FillFile(test, 1000);

    test.close();
}