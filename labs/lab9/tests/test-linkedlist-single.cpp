#include <iostream>
#include "../LLists.h"

bool testTailInsert();

int main()
{
    int errors;


    testTailInsert();


    if(errors > 0)
        return -1;
    else
        return 0;
}


bool testTailInsert()
{
    LinkedList<int>* list = new LinkedList<int>();

    std::cout << "Inserting numbers from 1...10" << std::endl;

    for(int i = 1; i < 11; i++)
    {
        list->InsertTail(i);
    }

    std::cout << "Checking list" << std::endl;



    for(int i = 1; i < 11; i++)
    {
        list->GoToHead();

        for(int i = 1; i < 11; i++)
        {
            if(i == list->GetData())
            {
                list->Next();
                continue;
            }
            else
            {
                std::cout << "FAILURE!" << std::endl;
                return false;
            }
        }

        return true;

    }
}