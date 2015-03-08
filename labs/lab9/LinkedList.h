#pragma once

#include <stddef.h>
#include "Node.h"

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *current;

    virtual Node<T>* GetTail();
    virtual Node<T>* GetHead();

    bool IsHead(Node<T>*);
    bool IsTail(Node<T>*);
    bool InList(Node<T>*);


public:
    LinkedList();
    ~LinkedList();


    void InsertHead(T);
    void InsertTail(T);

    void DeleteHead();
    T GetData();
    void GoToHead();
    void Next();


    bool IsEmpty();

};


#include "LinkedList.cpp"