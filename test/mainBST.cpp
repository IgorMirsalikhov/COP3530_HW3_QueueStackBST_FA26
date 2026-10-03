#include "BST.hpp"
#include <iostream>
#include <string>

int main() {
    // Test 1: Empty int tree
    BST<int> tree1;

    std::cout << "Empty int tree:\n";
    tree1.preorder();
    tree1.postorder();
    std::cout << "Height: " << tree1.height() << '\n';
    std::cout << "Leaf count: " << tree1.leafCount() << '\n';

    std::cout << '\n';


    // Test 2: Single-node double tree
    BST<double> tree2;
    tree2.insert(10.5);

    std::cout << "Single-node double tree:\n";
    tree2.preorder();
    tree2.postorder();
    std::cout << "Height: " << tree2.height() << '\n';
    std::cout << "Leaf count: " << tree2.leafCount() << '\n';

    std::cout << '\n';


    // Test 3: Larger string tree
    BST<std::string> tree3;

    tree3.insert("Mango");
    tree3.insert("Apple");
    tree3.insert("Peach");
    tree3.insert("Banana");
    tree3.insert("Orange");
    tree3.insert("Zebra");

    std::cout << "String tree:\n";
    tree3.inorder();
    tree3.preorder();
    tree3.postorder();
    std::cout << "Height: " << tree3.height() << '\n';
    std::cout << "Leaf count: " << tree3.leafCount() << '\n';

    return 0;
}