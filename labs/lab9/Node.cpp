#include "Node.h"

/*
    Deleting non-pointers throws a compiler error,
    these overloaded functions create a version of delete
    that will take appropriate action depending on the
    type passed to the template
 */
template <typename T>
void delete_if_ptr(T delVal) {}

template <typename T>
void delete_if_ptr(T* delVal) { delete delVal; }

/*
    Constructor and destructor for Linked list node.
    This should never be instantiated without data.
 */

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode)
{
    this->data = data;
    this->next = nextNode;
}

template <typename T>
Node<T>::~Node()
{
    delete_if_ptr(data);
}

/*
    Constructor and destructor for Doubly linked list node.
    This should never be instantiated without data.
 */

template <typename T>
DNode<T>::DNode(T data, DNode * prevNode, DNode * nextNode)
{
    this->data = data;
    this->next = nextNode;
    this->prev = prevNode;
}

template<typename T>
DNode<T>::~DNode()
{
    delete_if_ptr(this->data);
}


