#include <iostream>
using namespace std;

// Binary Tree Creation using Input + Recursion

// Tree Node
struct Node {
    Node* left;
    int data;
    Node* right;
    
    // Constructor to initialize a node
    Node (int data) {
        left = nullptr;
        this->data = data;
        right = nullptr;
    }
};

// Recursive function to build tree
Node* buildTree () {
    int val;
    cin >> val;

    // Base case
    if (val == -1) return nullptr;

    // Create current node
    Node* root = new Node (val);

    // Build left subtree
    root->left = buildTree ();

    // Build right subtree
    root->right = buildTree ();

    return root;
}

// Preorder traversal (for verification)
void preorder (Node* root) {
	if (root == nullptr) return;
	
	cout << root->data << " ";
	preorder (root->left);
	preorder (root->right);
}

int main () {
	cout << "Enter tree values (-1 for NULL):\n";
    Node* root = buildTree ();

    cout << "\nPreorder Traversal: ";
    preorder (root);
	
	return 0;
}

/*

Binary Tree:

        10
       /  \
      20   30
     /  \
    40  50

Example input:
10 20 40 -1 -1 50 -1 -1 30 -1 -1

Preorder Traversal: 10, 20, 40, 50, 30

*/