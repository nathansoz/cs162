#include <iostream>
#include "../LinkedList.h"

bool testHeadInsert();
bool testTailInsert();

int main()
{
    int errors;

    if(!testHeadInsert())
        errors++;
    if(!testTailInsert())
        errors++;

    std::cout << "Number of errors: " << errors << std::endl;

    if(errors > 0)
        return -1;
    else
        return 0;
}

bool testHeadInsert()
{

    LinkedList<int*>* list = new LinkedList<int*>();

    std::cout << "Inserting numbers from 1...10" << std::endl;

    for(int i = 1; i < 11; i++)
    {
        int* tmpInt = new int;
        *tmpInt = i;
        list->InsertHead(tmpInt);
    }

    std::cout << "Checking list" << std::endl;

    list->GoToHead();

    for(int i = 10; i <= 0; i--)
    {
        if(i == *(list->GetData()))
        {
            list->Next();
            continue;
        }
        else
        {
            std::cout << "FAILURE!" << std::endl;
            delete list;
            return false;
        }
    }

    delete list;

    return true;

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
            delete list;
            return false;
        }
    }

    delete list;


    return true;
}

