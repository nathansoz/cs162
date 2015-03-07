#include <stddef.h>
#include "LLists.h"

LinkedList::LinkedList()
{
    head = NULL;
    current = head;
}

template <typename T>
T LinkedList::GetData()
{
    if(current == NULL)
        return NULL;
    else
        return current->data;
}

template <typename T>
Node<T>* LinkedList::GetHead()
{
    return head;
}

template <typename T>
Node<T>* LinkedList::GetTail()
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

void LinkedList::GoToHead()
{
    current = head;
}

void LinkedList::Next()
{
    if(this->current->next == NULL)
        return;
    else
        this->current = this->current->next;
}

template <typename T>
void LinkedList::InsertAfter(T data, Node *)
{
    if (this->IsEmpty())
    {
        head = new Node(data, NULL);
        current = head;
    }
}

template <typename T>
void LinkedList::InsertHead(T data)
{
    if(this->IsEmpty())
    {
        head = new Node(data, NULL);
        current = head;
    }
    else
    {
        Node *tmpNode = new Node(data, head);
        head = tmpNode;
    }
}

template <typename T>
void LinkedList::InsertTail(T data)
{
    //If our list is empty, then inserting into the tail is just like inserting into the head
    if(head == NULL)
    {
        head = new Node(data, NULL);
    }
    else
    {
        Node* tail = GetTail();
        tail->next = new Node(data, NULL);
    }
}

bool LinkedList::InList(Node* nodeToFind)
{
    if(this->IsEmpty())
    {
        return false;
    }

    Node* currentNode = head;

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

bool LinkedList::IsEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

bool LinkedList::IsHead(Node* nodeToCheck)
{
    if(nodeToCheck == head)
        return true;
    else
        return false;
}

bool LinkedList::IsTail(Node * nodeToCheck)
{
    if(nodeToCheck == this->GetTail())
        return true;
    else
        return false;
}