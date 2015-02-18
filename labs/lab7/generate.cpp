#include <boost/random/mersenne_twister.hpp>

#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>


#include <fstream>
#include <iostream>

void FillFile(std::ofstream &outFile, int numGenerations)
{
    //Adapted from this example of c++11 random number generation:
    //  http://www.guyrutenberg.com/2014/05/03/c-mt19937-example/
    boost::mt19937 randomNum(time(0));
    boost::uniform_int<int> distribution(1, 9);

    boost::variate_generator< boost::mt19937&, boost::uniform_int<int> >
            generateRand( randomNum, distribution);

    if(outFile)
    {
        for(int i = 0; i < numGenerations; i++)
        {
            outFile << generateRand();
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