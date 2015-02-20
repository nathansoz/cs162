#include <boost/random/mersenne_twister.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>


#include <fstream>
#include <iostream>
#include <string>

enum zero_position{ EARLY_0, MID_0, LATE_0, NO_0};


template <typename RANDGEN, typename DISTTYPE, template<typename, typename> class GEN>
void FillFile(std::ofstream &outFile, GEN<RANDGEN, DISTTYPE>& generateRand, int numGenerations, zero_position zeroPos)
{



    if(outFile)
    {
        for(int i = 0; i < numGenerations; i++)
        {
            if(zeroPos == EARLY_0)
            {
                if(i == 0)
                {
                    outFile << 0;
                }
                else
                {
                    outFile << generateRand();
                }

            }
            else if(zeroPos == MID_0)
            {
                if(i == ((numGenerations - 1)/2))
                {
                    outFile << 0;
                }
                else
                {
                    outFile << generateRand();
                }

            }
            else if(zeroPos == LATE_0)
            {
                if(i == numGenerations - 1)
                {
                    outFile << 0;
                }
                else
                {
                    outFile << generateRand();
                }

            }
            else if(zeroPos == NO_0)
            {
                outFile << generateRand();
            }
        }
    }
    else
    {

    }

}

int main()
{
    int numberOfRandoms;
    std::string filePrefix;
    std::ofstream out;

    //setup our random number generator
    //Adapted from this example of c++11 random number generation:
    //  http://www.guyrutenberg.com/2014/05/03/c-mt19937-example/
    // I had to use boost libraries though

    boost::mt19937 randomNum(time(0));
    boost::uniform_int<int> distribution(1, 9);

    boost::variate_generator< boost::mt19937, boost::uniform_int<int> >
            generateRand( randomNum, distribution);

    //end prng setup

    std::cout << "Please enter the number of random numbers you would like in each file: ";
    std::cin >> numberOfRandoms;

    std::cin.ignore(1000, '\n');
    std::cout << "Please enter the prefix for the name of generated files: ";
    getline(std::cin, filePrefix);

    std::string earlyZero = filePrefix + "-early0.txt";
    std::string midZero = filePrefix + "-mid0.txt";
    std::string lateZero = filePrefix + "-late0.txt";
    std::string noZero = filePrefix + "-no0.txt";

    std::string files[] = {earlyZero, midZero, lateZero, noZero};
    zero_position zero_positions[] = {EARLY_0, MID_0, LATE_0, NO_0};
    for(int i = 0; i < 4; i++)
    {
        out.open(files[i].c_str());
        FillFile(out, generateRand, numberOfRandoms, zero_positions[i]);
        std::cout << "Filled file " << files[i] << " with random numbers." << std::endl;
        out.close();
    }

    return 0;


}