#include <algorithm>
#include <fstream>
#include <iostream>
#include <strings.h>
#include <iomanip>
#include <ncurses.h>
#include <form.h>
#include "Item.h"
#include "List.h"


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
        return true;
    }
}

bool validDouble(const char* tmpString, double &retVal)
{
    char* end;

    retVal = strtod(tmpString, &end);

    if(*end != '\0')
    {
        return false;
    }
    else
    {
        return true;
    }

}

List::List() {}

void List::AddItem()
{

    FIELD *field[5];
    FORM *add_form;
    field[0] = new_field(1, 50, 1, 18, 0, 0);
    field[1] = new_field(1, 50, 3, 18, 0, 0);
    field[2] = new_field(1, 50, 5, 18, 0, 0);
    field[3] = new_field(1, 50, 7, 18, 0, 0);
    field[4] = NULL;

    for(int i = 0; i < 5; i++)
    {
        set_field_back(field[i], A_UNDERLINE);
        field_opts_off(field[i], O_AUTOSKIP);
    }

    keypad(stdscr, true);
    wclear(stdscr);
    add_form = new_form(field);
    post_form(add_form);
    refresh();


    mvprintw(1, 0, "Name:");
    mvprintw(3, 0, "Unit:");
    mvprintw(5, 0, "Quantity:");
    mvprintw(7, 0, "Price per unit: ");
    move(1, 18);
    refresh();

    bool quit = false;

    int c;
    while((c = getch()) != KEY_F(1) && !quit)
    {
        switch (c)
        {
            case KEY_DOWN:
                form_driver(add_form, REQ_NEXT_FIELD);
                form_driver(add_form, REQ_END_LINE);
                break;
            case KEY_UP:
                form_driver(add_form, REQ_PREV_FIELD);
                form_driver(add_form, REQ_END_LINE);
                break;
            case KEY_BACKSPACE:
                form_driver(add_form, REQ_PREV_CHAR);
                form_driver(add_form, REQ_DEL_CHAR);
                break;
            case '\t':
                form_driver(add_form, REQ_NEXT_FIELD);
                form_driver(add_form, REQ_END_LINE);
                break;
            case KEY_BTAB:
                form_driver(add_form, REQ_PREV_FIELD);
                form_driver(add_form, REQ_END_LINE);
                break;
            case KEY_F(2):
            {
                char *nameC = field_buffer(field[0], 0);
                char *unitC = field_buffer(field[1], 0);
                char *qtyStr = field_buffer(field[2], 0);
                char *pricePerUnitStr = field_buffer(field[3], 0);

                std::string name = nameC;
                std::string unit = unitC;
                double qty;
                double pricePerUnit;

                validDouble(qtyStr, qty);
                validDouble(pricePerUnitStr, pricePerUnit);

                Item tmpItem(name, unit, qty, pricePerUnit);

                groceryList.push_back(tmpItem);
                quit = true;
                break;
            }
            default:
                form_driver(add_form, c);
                break;
        }

        if(quit)
        {
            break;
        }
    }


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
    int c;
    wclear(stdscr);
    move(0, 0);
    refresh();

    for(uint i = 0; i < groceryList.size(); i++)
    {
        char* newline = "\n";

        std::string name = groceryList.at(i).GetName();
        std::string unit = groceryList.at(i).GetUnit();
        double qty = groceryList.at(i).GetQty();
        double ppu = groceryList.at(i).GetPricePerUnit();
        name += '\n';
        unit += '\n';

        printw("Item: \n");
        printw("Name: ");
        printw(name.c_str());
        printw("Unit: ");
        printw(unit.c_str());
        printw("Quantity: ");
        printw("%f\n", qty);
        printw("Price Per Unit: ");
        printw("%.2f\n", ppu);
        printw(newline);
        //std::cout << "Item " << i << ":" << std::endl;
        //groceryList.at(i).Print();
        //std::cout << std::endl << std::endl;
    }

    while((c = getch()) != KEY_F(1))
    {
        switch (c)
        {
            default:
                break;
        }
    }

    //std::cout << "The list total is: $" << std::setprecision(2) << std::fixed << GetTotalCost() << std::endl;
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
