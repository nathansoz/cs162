#include <stddef.h>
#include "Node.h"
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    current = head;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* iterate = head;

    while(iterate != NULL)
    {
        Node<T>* tmp = iterate->next;
        delete iterate;
        iterate = tmp;
    }

}

template <typename T>
T LinkedList<T>::GetData()
{
    if(current == NULL)
        return NULL;
    else
        return current->data;
}

template <typename T>
Node<T>* LinkedList<T>::GetHead()
{
    return head;
}

template <typename T>
Node<T>* LinkedList<T>::GetTail()
{
    Node<T>* currentNode = head;

    while(true)
    {
        if(currentNode->next == NULL)
        {
            return currentNode;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
}


template <typename T>
void LinkedList<T>::GoToHead()
{
    current = head;
}


template <typename T>
void LinkedList<T>::Next()
{
    if(this->current->next == NULL)
        return;
    else
        this->current = this->current->next;
}

template <typename T>
void LinkedList<T>::InsertHead(T data)
{
    if(this->IsEmpty())
    {
        head = new Node<T>(data, NULL);
        current = head;
    }
    else
    {
        Node<T> *tmpNode = new Node<T>(data, head);
        head = tmpNode;
    }
}

template <typename T>
void LinkedList<T>::InsertTail(T data)
{
    //If our list is empty, then inserting into the tail is just like inserting into the head
    if(head == NULL)
    {
        head = new Node<T>(data, NULL);
    }
    else
    {
        Node<T>* tail = GetTail();
        tail->next = new Node<T>(data, NULL);
    }
}

template <typename T>
bool LinkedList<T>::InList(Node<T>* nodeToFind)
{
    if(this->IsEmpty())
    {
        return false;
    }

    Node<T>* currentNode = head;

    while(true)
    {
        if(currentNode == NULL)
            return false;
        else if(currentNode == nodeToFind)
            return true;
        else
            continue;
    }

}

template <typename T>
bool LinkedList<T>::IsEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

template <typename T>
bool LinkedList<T>::IsHead(Node<T>* nodeToCheck)
{
    if(nodeToCheck == head)
        return true;
    else
        return false;
}

template <typename T>
bool LinkedList<T>::IsTail(Node<T> * nodeToCheck)
{
    if(nodeToCheck == this->GetTail())
        return true;
    else
        return false;
}

template <typename T>
void LinkedList<T>::DeleteHead()
{
    if(head == NULL)
        return;
    else
    {
        Node<T>* tmp = head;
        head = tmp->next;
        delete tmp;
    }
}