#pragma once

template<typename T>
class Node
{
public:
    Node(T, Node<T>*);
    ~Node();
    T data;
    Node<T> *next;
};


template<typename T>
class DNode
{
public:
    DNode(T, DNode<T>*, DNode<T>*);
    ~DNode();
    T data;

    DNode<T> *next;
    DNode<T> *prev;


};

#include "Node.cpp"