#include <ctype.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

void ReadFile(std::string fileName, std::vector<int> *retVector)
{
    std::ifstream input;


    input.open(fileName.c_str());

    if(input.is_open())
    {
        while(input.peek() != EOF)
        {
            char inChar;
            input.get(inChar);

            if(isdigit(inChar))
            {
                retVector->push_back(inChar - 48);
            }
        }
    }

    input.close();
}

void BubbleSort(std::vector<int> *sortArray)
{
    std::clock_t t;
    t = clock();
    for(int i = sortArray->size() - 1; i > - 1; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(sortArray->at(j) < sortArray->at(j + 1) || sortArray->at(j) == sortArray->at(j + 1))
            {
                continue;
            }
            else
            {
                char tmp = sortArray->at(j);
                sortArray->at(j) = sortArray->at(j + 1);
                sortArray->at(j + 1) = tmp;
            }
        }
    }

    t = clock() - t;
    std::cout << "Total time was " << t << " processor cycles." << std::endl;
}


int main()
{
    std::string inFileName = "";
    std::string outFileName = "";

    while(inFileName == "")
    {
        std::cout << "Please type the filename that you would like to sort: ";
        getline(std::cin, inFileName);
    }

    std::vector<int> *sortChars = new std::vector<int>;
    ReadFile(inFileName, sortChars);
    if(sortChars->size() == 0)
    {
        std::cout << "File does not exist!" << std::endl;

    }
    BubbleSort(sortChars);

    while(outFileName == "")
    {
        std::cout << "File sorted. Output to filename: ";
        getline(std::cin, outFileName);
    }

    std::ofstream outstream;
    outstream.open(outFileName.c_str());
    for(int i = 0; i < sortChars->size(); i++)
    {
        outstream.put(sortChars->at(i) + 48);
    }

    outstream.close();

    return 0;
}