#include "Stack.h"

template<typename T>
Stack<T>::Stack()
{
    stack = new LinkedList<T>();
}

template<typename T>
Stack<T>::~Stack()
{
    delete stack;
}



template<typename T>
bool Stack<T>::IsEmpty()
{
    return this->stack->IsEmpty();
}

template<typename T>
T Stack<T>::Peek()
{
    stack->GoToHead();
    return stack->GetData();
}

template<typename T>
void Stack<T>::Pop()
{
    if(this->IsEmpty())
        return;

    stack->DeleteHead();
}

template<typename T>
void Stack<T>::Push(T data)
{
    stack->InsertHead(data);
}
