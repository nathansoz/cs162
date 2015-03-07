template<typename T>
class Node
{
public:
    Node(T, Node<T>*);
    T data;
    Node<T> *next;
};