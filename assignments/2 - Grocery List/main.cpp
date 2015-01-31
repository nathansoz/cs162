/* Author: Nathan Sosnovske
*
* Created: 1/29/15
*
* Edited: 1/29/15
*
* Files: Item.cpp, Item.h, List.cpp, List.h, main.cpp
*
* Overview:
* Menu logic for grocery list program.
*
* Input:
*  User choice
*
* Output:
*  User choice
*
*/

//library imports
#include <fstream>
#include <iostream>
#include <string>


//custom headers
#include "List.h"
#include "Item.h"

//Helper functions to validate user input of numbers
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
//end helper functions

//Main program loop. Will loop until user chooses option 6
int main()
{
    List groceryList;
    int choice;

    std::cout << std::endl << "Welcome to the grocery list program!" << std::endl;

    do
    {
        choice = -1;

        std::cout << std::endl << "Please make a selection" << std::endl;
        std::cout << "1) Add list item." << std::endl;
        std::cout << "2) Delete list item" <<std::endl;
        std::cout << "3) Print list" << std::endl;
        std::cout << "4) Save list to file" << std::endl;
        std::cout << "5) Load list from file" << std::endl;
        std::cout << "6) Exit" << std::endl;
        std::cout << "Choice: ";

        //Get the input and sanity check. Ensure that it is in range and a valid integer
        while(choice < 1 || choice > 6)
        {
            std::string strChoice;
            getline(std::cin, strChoice);

            if(!validInt(strChoice.c_str(), choice))
            {
                std::cout << "invalid selection!" << std::endl;
                std::cout << "Choice: ";
                continue;
            }

            if(choice < 1 || choice > 6)
            {
                std::cout << "invalid selection!" << std::endl;
                std::cout << "Choice: ";
                continue;
            }


        }

        //All of the menu choice logic happens here. Mostly input processing and calls to the List and Item libraries
        //I did choose to check my filename input here instead of in the libraries... I'm not sure which is the
        //better choice....
        switch(choice)
        {
            //ADD ITEM
            case 1:
            {
                std::string name;
                std::string unit;
                std::string qtyTmpString;
                std::string pricePerUnitTempString;
                double qty;
                double pricePerUnit;

                std::cout << std::endl << "Please enter the name of the item: ";
                getline(std::cin, name);
                std::cout << "Please enter the unit of measure: ";
                getline(std::cin, unit);

                while(true)
                {
                    std::cout << "Please enter the quantity: ";
                    getline(std::cin, qtyTmpString);
                    if(qtyTmpString.length() > 0 && validDouble(qtyTmpString.c_str(), qty))
                    {
                        if(qty > 0)
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "Zero or negative is not a valid quantity." << std::endl;
                            continue;
                        }

                    }
                    else
                    {
                        std::cout << "Invalid double!" << std::endl;
                        continue;
                    }
                }

                while(true)
                {
                    std::cout << "Please enter the price per unit (no dollar symbol): ";
                    getline(std::cin, pricePerUnitTempString);
                    if(pricePerUnitTempString.length() > 0 && validDouble(pricePerUnitTempString.c_str(), pricePerUnit))
                    {
                        if(pricePerUnit > 0)
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "Zero or negative is not a valid price." << std::endl;
                            continue;
                        }
                    }
                    else
                    {
                        std::cout << "Invalid double!" << std::endl;
                        continue;
                    }
                }

                Item tmpItem(name, unit, qty, pricePerUnit);
                groceryList.AddItem(tmpItem);
                break;
            }

            //DELETE ITEM (BY INDEX)
            case 2:
            {
                int index;
                std::string indexTempString;

                std::cout << std::endl;
                groceryList.PrintList();
                std::cout << std::endl;
                std::cout << std::endl << "Please enter the index of the item you would like to delete (list printed for your convenience: ";
                getline(std::cin, indexTempString);

                if(validInt(indexTempString.c_str(), index))
                {
                    if(index < groceryList.GetCount())
                    {
                        groceryList.DeleteItem(index);
                    }
                    else
                    {
                        std::cout << "Index out of range! Going to main menu." << std::endl;
                    }
                }
                else
                {
                    std::cout <<"Invalid int! Going to main menu.";
                }
                break;
            }

            //PRINT LIST
            case 3:
            {
                std::cout << std::endl;
                groceryList.PrintList();
                break;
            }

            //SAVE LIST TO FILE
            case 4:
            {
                std::string fileName = "";
                std::ofstream outFile;

                while(fileName.length() == 0)
                {
                    std::cout << std::endl << "Please enter a filename to save to: ";
                    getline(std::cin, fileName);
                }

                outFile.open(fileName.c_str());
                groceryList.WriteListToFile(outFile);
                outFile.close();
                break;
            }

            //READ LIST FROM FILE
            case 5:
            {
                std::string fileName = "";
                std::ifstream inFile;

                while(fileName.length() == 0)
                {
                    std::cout << std::endl <<
                                "Please enter a filename to read from (this will clear the current list in memory, type 'return' to keep list in memory): ";
                    getline(std::cin, fileName);
                }

                if(fileName == "return")
                {
                    break;
                }

                inFile.open(fileName.c_str());

                if(inFile.is_open())
                {
                    groceryList.ReadListFromFile(inFile);
                    inFile.close();
                }
                else
                {
                    inFile.close();
                    std::cout << "File does not exist! Returning to main menu!" << std::endl << std::endl;
                }

                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                break;
            }
        }


    } while(true);

    //we will never get here
    return 0;
}