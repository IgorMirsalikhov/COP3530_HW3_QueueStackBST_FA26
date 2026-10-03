#ifndef STACK_HPP
#define STACK_HPP


template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void        push(const T& val);
    bool        empty() const;
    void        print() const;
    T           pop();
    const T&    top() const;
    
private:
    template <typename U>
    class Node {
        public:
            U data;
            Node<U>* next;
            Node(const U& val = U(), Node<U>* n = nullptr) : data(val), next(n) {}
    };
    Node<T>* top_node;
};

#include "Stack.tpp"

#endif