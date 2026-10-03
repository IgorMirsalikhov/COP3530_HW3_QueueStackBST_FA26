#include "BST.hpp"
#include <iostream>

template <typename T>
BST<T>::BST() : root(nullptr) {
    
}


template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = root;

    // Iterate through BST
    while (cur) {
        parent = cur;

        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (val < parent->data) {
        parent->left = new BTNode<T>(val);
    }
    else {
        parent->right = new BTNode<T>(val);
    }
}

template <typename T>
bool BST<T>::contains(const T& val) const {
    const BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) {
            return true;
        }
        else if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return false;
}

template <typename T>
const BTNode<T>* BST<T>::search(const BTNode<T>* node, const T& val) const {
    // Base case
    if (!node || node->data == val) {
        return node;
    }
    else if (val < node->data) {
        return search(node->left, val);
    }
    else {
        return search(node->right, val);
    }
}

template <typename T>
const BTNode<T>* BST<T>::search(const T& val) const {
    return search(root, val);
}

template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::inorder(const BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}
