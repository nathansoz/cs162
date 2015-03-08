#include <stddef.h>
#include "Node.h"
#include "DLinkedList.h"

template <typename T>
DLinkedList<T>::DLinkedList()
{
    head = NULL;
    current = head;
}

template<typename T>
DLinkedList<T>::~DLinkedList()
{
    DNode<T>* iterate = head;

    while(iterate != NULL)
    {
        DNode<T>* tmp = iterate->next;
        delete iterate;
        iterate = tmp;
    }

}

template <typename T>
T DLinkedList<T>::GetData()
{
    if(current == NULL)
        return NULL;
    else
        return current->data;
}

template <typename T>
DNode<T>* DLinkedList<T>::GetHead()
{
    return head;
}

template <typename T>
DNode<T>* DLinkedList<T>::GetTail()
{
    DNode<T>* currentDNode = head;

    while(true)
    {
        if(currentDNode->next == NULL)
        {
            return currentDNode;
        }
        else
        {
            currentDNode = currentDNode->next;
        }
    }
}


template <typename T>
void DLinkedList<T>::GoToHead()
{
    current = head;
}


template <typename T>
void DLinkedList<T>::Next()
{
    if(this->current->next == NULL)
        return;
    else
        this->current = this->current->next;
}

template <typename T>
void DLinkedList<T>::Prev()
{
    if(this->current->prev == NULL)
        return;
    else
        this->current = this->current->prev;
}

template <typename T>
void DLinkedList<T>::InsertHead(T data)
{
    if(this->IsEmpty())
    {
        head = new DNode<T>(data, NULL, NULL);
        current = head;
    }
    else
    {
        DNode<T> *tmpDNode = new DNode<T>(data, NULL, head);
        head->prev = tmpDNode;
        head = tmpDNode;
    }
}

template <typename T>
void DLinkedList<T>::InsertTail(T data)
{
    //If our list is empty, then inserting into the tail is just like inserting into the head
    if(head == NULL)
    {
        head = new DNode<T>(data, NULL, NULL);
    }
    else
    {
        DNode<T>* tail = GetTail();
        tail->next = new DNode<T>(data, tail, NULL);
    }
}

template <typename T>
bool DLinkedList<T>::InList(DNode<T>* DNodeToFind)
{
    if(this->IsEmpty())
    {
        return false;
    }

    DNode<T>* currentDNode = head;

    while(true)
    {
        if(currentDNode == NULL)
            return false;
        else if(currentDNode == DNodeToFind)
            return true;
        else
            continue;
    }

}

template <typename T>
bool DLinkedList<T>::IsEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

template <typename T>
bool DLinkedList<T>::IsHead(DNode<T>* DNodeToCheck)
{
    if(DNodeToCheck == head)
        return true;
    else
        return false;
}

template <typename T>
bool DLinkedList<T>::IsTail(DNode<T> * DNodeToCheck)
{
    if(DNodeToCheck == this->GetTail())
        return true;
    else
        return false;
}

template <typename T>
void DLinkedList<T>::DeleteHead()
{
    if(head == NULL)
        return;
    else
    {
        DNode<T>* tmp = head;
        head = tmp->next;
        delete tmp;
    }
}