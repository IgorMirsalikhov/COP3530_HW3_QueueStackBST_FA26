#include "Stack.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
Stack<T>::Stack() {
    top_node = nullptr;
}


template <typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void        Stack<T>::push(const T& val) {
    if (empty()) {
        top_node = new Node<T>(val);
    }
    else {
        Node<T>* new_node = new Node<T>(val, top_node);
        top_node = new_node;
    }
}


template <typename T>
bool        Stack<T>::empty() const {
    return top_node == nullptr;
}

template <typename T>
void        Stack<T>::print() const {
    std::cout << "[ ";
    const Node<T>* cur = top_node;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << ", ";
        }
        cur = cur->next;
    }
    std::cout << " ]\n";
}

template <typename T>
T           Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Emtpy stack");
    }
    
    Node<T>* to_delete = top_node;
    T to_return = top_node->data;

    top_node = top_node->next;
    
    delete to_delete;
    return to_return; 
}

template <typename T>
const T&    Stack<T>::top() const {
    if (!empty()) {
        return top_node->data;
    }
    else {
        throw std::out_of_range("Emtpy stack");
    }
}
    