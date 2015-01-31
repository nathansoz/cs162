#include <fstream>
#include <iostream>
#include <strings.h>
#include <iomanip>
#include "Item.h"
#include "List.h"

List::List() {}

void List::AddItem(Item &item)
{
    groceryList.push_back(item);
}


//GETTERS
int List::GetCount()
{
    return groceryList.size();
}

Item List::GetItem(int index)
{
    return groceryList.at(index);
}

double List::GetTotalCost()
{
    double total = 0;

    for(uint i = 0; i < groceryList.size(); i++)
    {
        total += groceryList.at(i).GetTotal();
    }

    return total;
}
//END GETTERS


void List::DeleteItem(int index)
{
    groceryList.erase(groceryList.begin() + index);
}

void List::PrintList()
{
    for(uint i = 0; i < groceryList.size(); i++)
    {
        std::cout << "Item " << i << ":" << std::endl;
        groceryList.at(i).Print();
        std::cout << std::endl << std::endl;
    }

    std::cout << "The list total is: $" << std::setprecision(2) << std::fixed << GetTotalCost() << std::endl;
}

void List::ReadListFromFile(std::ifstream &inFile)
{
    std::string tmpLine;
    bool validFile = false;

    if(getline(inFile, tmpLine))
    {
        //we don't want our user grabbing an ordinary file
        //So let's make sure it is part of GroceryApp
        if(tmpLine == "GroceryApp")
        {
            if(getline(inFile, tmpLine))
            {
                if(tmpLine == "Version 1.0")
                {
                    validFile = true;
                }
                
            }
        }
        else
        {
            std::cout << "File does not appear to be the type that this ptogram can read." <<std::endl;
        }
    }
    else
    {
        std::cout << "Could not read from file." << std::endl;
        return;
    }

    if(validFile)
    {
        while(inFile.peek() != EOF)
        {
            std::string name;
            std::string unit;
            std::string qty;
            std::string pricePerUnit;

            if(!getline(inFile, name))
            {
                std::cout << "Error getting record" << std::endl;
                groceryList.clear();
                return;
            }
            if(!getline(inFile, unit))
            {
                std::cout << "Error getting record" << std::endl;
                groceryList.clear();
                return;
            }
            if(!getline(inFile, qty))
            {
                std::cout << "Error getting record" << std::endl;
                groceryList.clear();
                return;
            }
            if(!getline(inFile, pricePerUnit))
            {
                std::cout << "Error getting record" << std::endl;
                groceryList.clear();
                return;
            }

            Item tmpItem(name, unit, atoi(qty.c_str()), strtod(pricePerUnit.c_str(), NULL));
            groceryList.push_back(tmpItem);
        }
    }
    else
    {
        std::cout << "Invalid file!" << std::endl;
        return;
    }

}

void List::WriteListToFile(std::ofstream &outFile)
{
    outFile << "GroceryApp" << '\n';
    outFile << "Version 1.0" << '\n';
    for(uint i = 0; i < groceryList.size(); i++)
    {
        outFile << groceryList.at(i).GetName() << '\n';
        outFile << groceryList.at(i).GetUnit() << '\n';
        outFile << groceryList.at(i).GetQty() << '\n';
        outFile << groceryList.at(i).GetPricePerUnit() << '\n';
    }

}
