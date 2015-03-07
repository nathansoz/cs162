#pragma once

#include <stddef.h>
#include "Node.h"

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

    T GetData();
    void GoToHead();
    void Next();
    void Prev();
    void DeleteHead();


    bool IsEmpty();

};


#include "DLinkedList.cpp"