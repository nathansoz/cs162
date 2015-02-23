#include <iostream>
#include <vector>
#include <fstream>
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

int search(std::vector<int> *searchVector, int searchVal)
{
    std::clock_t t;
    int retVal = -1;

    t = clock();
    for(int i = 0; i < searchVector->size(); i++)
    {
        if(searchVector->at(i) == searchVal)
        {
            t = clock() - t;
            std::cout << "Total time was " << t << " processor cycles." << std::endl;
            return i;

        }
    }

    t = clock() - t;
    std::cout << "Total time was " << t << " processor cycles." << std::endl;

    return retVal;

}

int main()
{
    std::string inFileName = "";

    while(inFileName == "")
    {
        std::cout << "Please type the filename that you would like to search for 0 in: ";
        getline(std::cin, inFileName);
    }

    std::vector<int> *searchInts = new std::vector<int>;
    ReadFile(inFileName, searchInts);
    if(searchInts->size() == 0)
    {
        std::cout << "File does not exist!" << std::endl;
        exit(1);
    }

    int position = search(searchInts, 0);

    if(position == -1)
    {
        std::cout << std::endl << "No 0 found!" << std::endl;
    }
    else
    {
        std::cout << std::endl << "Found 0 at position: " << position << " (0-indexed)" << std::endl;
    }

    return 0;
}