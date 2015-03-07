#include "Node.h"

template <typename T>
Node::Node(T data, Node<T>* nextNode)
{
    this->data = data;
    this->next = nextNode;
}