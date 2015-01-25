#include <fstream>
#include <iostream>
#include <string>

#include "List.h"
#include "Item.h"

//todo: fix this
bool validInt(const char* tmpString, int &retVal)
{
    long convertVal;
    char* end;

    convertVal = strtol(tmpString, &end, 10);

    if(*end != '\0')
    {
        return false;
    }
    else
    {
        retVal = static_cast<int>(convertVal);
    }
}

int main()
{
    List groceryList;

    std::cout << "Welcome to the grocery list program!" << std::endl;

    do
    {
        int choice = -1;

        std::cout << "Please make a selection" << std::endl;
        std::cout << "1) Add list item." << std::endl;
        std::cout << "2) Delete list item" <<std::endl;
        std::cout << "3) Print list" << std::endl;
        std::cout << "4) Save list to file" << std::endl;
        std::cout << "5) Load list from file" << std::endl;
        std::cout << "Choice: ";

        while(choice < 1 || choice > 5)
        {
            std::string strChoice;
            int choice;
            getline(std::cin, strChoice);

            if(!validInt(strChoice.c_str(), choice))
            {
                std::cout << "invalid selection!" << std::endl;
                std::cout << "Choice: ";
                continue;
            }



            if(choice < 1 || choice > 5)
            {
                std::cout << "invalid selection!" << std::endl;
                std::cout << "Choice: ";
                continue;
            }
        }

        exit(0);
    } while(true);

}