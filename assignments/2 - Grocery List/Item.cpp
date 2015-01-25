#include "Item.h"
#include <iostream>
#include <string>
#include <iomanip>

Item::Item(std::string name, std::string unit, int qty, double pricePerUnit)
{
    this->name = name;
    this->unit = unit;
    this->qty = qty;
    this->pricePerUnit = pricePerUnit;
    this->total = pricePerUnit * static_cast<double>(qty);
}

std::string Item::GetName()
{
    return name;
}

std::string Item::GetUnit()
{
    return unit;
}

int Item::GetQty()
{
    return qty;
}

double Item::GetPricePerUnit()
{
    return pricePerUnit;
}

double Item::GetTotal()
{
    return total;
}

void Item::Print()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Unit: " << unit << std::endl;
    std::cout << "Quantity: " << qty << std::endl;
    std::cout << "Price Per Unit: $" << std::setprecision(2) << std::fixed << pricePerUnit << std::endl;
    std::cout << "Total: $" << std::setprecision(2) << std::fixed << total << std::endl;
}