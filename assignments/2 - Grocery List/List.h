#pragma once
//external libs
#include <fstream>
#include <string>
#include <vector>

//internal libs

#include "Item.h"


class List
{
    private:
        std::vector<Item> groceryList;

    public:
        List();
        void AddItem(Item&);
        void DeleteItem(int);
        int GetCount();
        Item GetItem(int);
        double GetTotalCost();

        void PrintList();

        void ReadListFromFile(std::ifstream&);
        void WriteListToFile(std::ofstream&);




};