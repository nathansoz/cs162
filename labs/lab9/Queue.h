#pragma once

#include "DLinkedList.h"

template <typename T>
class Queue
{
private:
    DLinkedList<T>* queue;
public:
    Queue();
    ~Queue();

    void AddBack(T);
    T GetFront();
    void RemoveFront();
    bool IsEmpty();

};

#include "Queue.cpp"