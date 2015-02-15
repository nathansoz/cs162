#include <iostream>
#include <vector>
#include <fstream>

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

int binarySearch(std::vector<int> *searchVector, int start, int end, int searchVal)
{
    int midpoint = (start + end) / 2;

    if(start > end)
    {
        return -1;
    }
    if(searchVector->at(midpoint) == searchVal)
    {
        return midpoint;
    }
    if(searchVector->at(midpoint) < searchVal)
    {
        return binarySearch(searchVector, midpoint + 1, end, searchVal);
    }
    else
    {
        return binarySearch(searchVector, start, midpoint - 1, searchVal);
    }

}

int main()
{
    std::string inFileName = "";

    while(inFileName == "")
    {
        std::cout << "Please type the filename that you would like to search for 5 in: ";
        getline(std::cin, inFileName);
    }

    std::vector<int> *searchInts = new std::vector<int>;
    ReadFile(inFileName, searchInts);
    if(searchInts->size() == 0)
    {
        std::cout << "File does not exist!" << std::endl;
        exit(1);
    }

    int position = binarySearch(searchInts, 0, searchInts->size(), 5);

    if(position == -1)
    {
        std::cout << std::endl << "No 5 found!" << std::endl;
    }
    else
    {
        std::cout << std::endl << "Found 5 at position: " << position << " (0-indexed)" << std::endl;
    }

    return 0;
}