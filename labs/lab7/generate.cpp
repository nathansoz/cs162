#include <boost/random/mersenne_twister.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>


#include <fstream>
#include <iostream>


template <typename RANDGEN, typename DISTTYPE, template<typename, typename> class GEN>
void FillFile(std::ofstream &outFile, GEN<RANDGEN, DISTTYPE>& generateRand, int numGenerations)
{



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
    //setup our random number generator
    //Adapted from this example of c++11 random number generation:
    //  http://www.guyrutenberg.com/2014/05/03/c-mt19937-example/
    // I had to use boost libraries though

    boost::mt19937 randomNum(time(0));
    boost::uniform_int<int> distribution(1, 9);

    boost::variate_generator< boost::mt19937, boost::uniform_int<int> >
            generateRand( randomNum, distribution);

    //end prng setup

    std::ofstream test;
    test.open("blah.txt");

    FillFile(test, generateRand, 1000);

    test.close();
}