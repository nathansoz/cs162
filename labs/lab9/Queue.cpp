#include "Queue.h"

template<typename T>
Queue<T>::Queue()
{
    queue = new DLinkedList<T>();
}

template<typename T>
Queue<T>::~Queue()
{
    delete queue;
}


template<typename T>
void Queue<T>::AddBack(T data)
{
    queue->InsertTail(data);
}

template<typename T>
T Queue<T>::GetFront()
{
    queue->GoToHead();
    return queue->GetData();
}

template<typename T>
void Queue<T>::RemoveFront()
{
    queue->DeleteHead();
}

template<typename T>
bool Queue<T>::IsEmpty()
{
    return queue->IsEmpty();
}