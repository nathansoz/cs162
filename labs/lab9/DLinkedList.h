#pragma once

#include <stddef.h>
#include "Node.h"

/*
    Implementation for a linked list in which one can go
    forward and backwards (Doubly linked list)
 */

template <typename T>
class DLinkedList
{
private:
    DNode<T> *head;
    DNode<T> *current;

    virtual DNode<T>* GetTail();
    virtual DNode<T>* GetHead();

    bool IsHead(DNode<T>*);
    bool IsTail(DNode<T>*);
    bool InList(DNode<T>*);


public:
    DLinkedList();
    ~DLinkedList();


    void InsertHead(T);
    void InsertTail(T);

    void DeleteHead();
    T GetData();
    void GoToHead();
    void Next();
    void Prev();

    bool IsEmpty();

};


#include "DLinkedList.cpp"