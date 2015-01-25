#pragma once

#include <string>

class Item
{
    private:
        std::string name;
        std::string unit;
        int qty;
        double pricePerUnit;
        double total;

    public:
        Item();
        Item(std::string, std::string, int, double);

        std::string GetName();
        std::string GetUnit();
        int GetQty();
        double GetPricePerUnit();
        double GetTotal();

        void Print();
};