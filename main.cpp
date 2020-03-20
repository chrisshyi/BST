#include "bst.h"
#include <iostream>

int main() {
    BST<int> bst;
    bst.insert(10);
    bst.insert(15);
    bst.insert(12);
    bst.insert(18);

    std::cout << bst.in_order_traversal() << std::endl;

    return 1;
}