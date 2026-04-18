#include <iostream>
using namespace std;

// Search in Binary Search Trees

Node search_bst (Node* root, int key) {
    // base case
    if (!root || root->val == key) return root;
    
    if (root->val > key) {
        return search_bst (root->left, key);
    }
    else {
        return search_bst (root->right, key);
    }
}

int main () {

    return 0;
}

// Time-complexity: O(log n)