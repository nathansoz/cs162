#include "SozLibs/Dice.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>


void TestStack()
{
    SozLibs::Dice* die = new SozLibs::Dice(10);
    Stack<int>* test = new Stack<int>();

    std::cout << std::endl << "Pushing random numbers on to stack... ";

    for(int i = 0; i < 10; i++)
    {
        int number = die->rollDie();
        std::cout << number << " ";
        test->Push(number);
    }

    std::cout << std::endl << "Pop out numbers in FILO order... ";

    while(!test->IsEmpty())
    {
        std::cout << test->Peek() << " ";

        test->Pop();
    }

    delete test;
    delete die;
}

void TestQueue()
{
    SozLibs::Dice* die = new SozLibs::Dice(10);
    Queue<int>* test = new Queue<int>();

    std::cout << std::endl <<  "Pushing random numbers on to queue... ";

    for(int i = 0; i < 10; i++)
    {
        int number = die->rollDie();
        std::cout << number << " ";
        test->AddBack(number);
    }

    std::cout << std::endl << "Pop out numbers in FIFO order... ";

    while(!test->IsEmpty())
    {
        std::cout << test->GetFront() << " ";

        test->RemoveFront();
    }

    delete test;
    delete die;

}

int main()
{
    srand(time(NULL));
    TestStack();
    TestQueue();

    std::cout << std::endl;
}
