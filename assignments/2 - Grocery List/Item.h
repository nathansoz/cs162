#pragma once

#include <string>

class Item
{
    private:
        std::string name;
        std::string unit;
        double qty;
        double pricePerUnit;
        double total;

    public:
        Item();
        Item(std::string, std::string, double, double);

        std::string GetName();
        std::string GetUnit();
        int GetQty();
        double GetPricePerUnit();
        double GetTotal();

        void Print();
};