#include "Node.h"

template <typename T>
class LinkedList
{
private:


    Node<T> *head;
    Node<T> *current;

    Node<T>* GetTail();
    Node<T>* GetHead();

    bool IsHead(Node<T>*);
    bool IsTail(Node<T>*);
    bool InList(Node<T>*);

    void InsertAfter(T, Node<T>*);

public:
    LinkedList();


    void InsertHead(T);
    void InsertTail(T);

    T GetData();
    void GoToHead();
    void Next();


    bool IsEmpty();

};