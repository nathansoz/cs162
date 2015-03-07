#include "Node.h"

template <typename T>
void delete_if_ptr(T delVal) {}

template <typename T>
void delete_if_ptr(T* delVal) { delete delVal; }

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


