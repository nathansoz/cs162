#include <stddef.h>
#include "Node.h"
#include "LinkedList.h"

/*
    Constructor
 */

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    current = head;
}

/*
    Destructor ~LinkedList()

    Iterates over every node and calls delete on it. The node data type is responsible for
    cleaning up the data that it contains
 */

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


/*
    Public API Functions
 */



/*
    void LinkedList<T>::InsertHead(T data)

    Allows user to insert data of type T at the head of the linked list.
    Performs all relevant pointer manipulations.

    Depends on: LinkedList<T>::IsEmpty()
 */

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

/*
    void LinkedList<T>::InsertTail(T data)

    Allows user to insert data of type T at the tail of the linked list.
    Performs all relevant pointer manipulations.

    Depends on: LinkedList<T>::IsEmpty()
 */

template <typename T>
void LinkedList<T>::InsertTail(T data)
{
    //If our list is empty, then inserting into the tail is just like inserting into the head
    if(this->IsEmpty())
    {
        head = new Node<T>(data, NULL);
    }
    else
    {
        Node<T>* tail = GetTail();
        tail->next = new Node<T>(data, NULL);
    }
}

/*
    void LinkedList<T>::DeleteHead()

    Removes the head of the linked list and makes the next element (or NULL)
    the head of the list. Should be improved to signal to user if list is empty.

    Depends on: LinkedList<T>::IsEmpty()
 */

template <typename T>
void LinkedList<T>::DeleteHead()
{
    if(this->IsEmpty())
        return;
    else
    {
        Node<T>* tmp = head;
        head = tmp->next;
        delete tmp;
    }
}

/*
    T LinkedList<T>::GetData()

    Simply returns the data in the "current" node. Returns NULL if the linked list is empty.

 */

template <typename T>
T LinkedList<T>::GetData()
{
    if(current == NULL)
        return NULL;
    else
        return current->data;
}

/*
    void LinkedList<T>::GoToHead()

    Public interface allowing the user to move the current pointer to
    the head of the list. This, along with the Next() function, allow the user
    to iterate over the list.
 */

template <typename T>
void LinkedList<T>::GoToHead()
{
    current = head;
}

/*
    void LinkedList<T>::Next()

    Moves the current pointer to the next item in the list. If the user is at the end of
    the list, it does nothing. Setting the pointer to NULL may be a better idea...
 */

template <typename T>
void LinkedList<T>::Next()
{
    if(this->current->next == NULL)
        return;
    else
        this->current = this->current->next;
}

/*
    bool LinkedList<T>::IsEmpty()

    Simply checks to see if the list contains any elements.
 */

template <typename T>
bool LinkedList<T>::IsEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}





/*
    Private implementation functions

 */

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

