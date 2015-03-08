#pragma once

#include "LinkedList.h"

template <typename T>
class Stack
{
private:
    LinkedList<T>* stack;
public:
    Stack();
    ~Stack();

    void Push(T);
    T Peek();
    void Pop();
    bool IsEmpty();

};

#include "Stack.cpp"