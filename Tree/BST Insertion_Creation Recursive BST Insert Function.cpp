#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node (int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive BST Insert Function
void insertBST (Node*& root, int val) {
    // Base case
    if (!root) {
        root = new Node (val);
        return;
    }
    
    // Smaller value goes to left subtree
    if (val < root->data) {
        insertBST (root->left, val);
    } 
    // Larger value goes to right subtree
    else if (val > root->data) {
        insertBST (root->right, val);
    }

    // If val == root->data, ignore duplicates (or handle separately)
}

// Inorder traversal (for verification)
void inorder (Node* root) {
    if (!root) return;
    
    inorder (root->left);
    cout << root->data << " ";
    inorder (root->right);
}

int main () {
    Node* root = nullptr;
    insertBST (root, 40);
    insertBST (root, 20);
    insertBST (root, 10);
    insertBST (root, 70);
    insertBST (root, 90);
    
    cout << "Inorder Traversal: ";
    inorder (root);
    
    return 0;
}

/*

          50						
        /    \
      30      70
     /  \    /  \
   20   40  60   80


A Binary Search Tree (BST) is a special type of binary tree that maintains a specific order among its nodes, allowing efficient search, insertion, and deletion operations.

Key Properties of a BST:
1. Node Structure:
	Each node has at most two children: left and right.
	Each node contains a value (or key).
	
2. Order Property:
	For every node:
		All values in its left subtree are less than the node's value. 		Max value of left subtree must be less than current node.
		All values in its right subtree are greater than the node's value.	Min value of right subtree must be greater than or equal to current node.
	
3. Unique or Duplicate Values:
	Typically, BSTs do not contain duplicate values, but variations exist that allow duplicates.


The minimum value is found at the leftmost node.
The maximum value is found at the rightmost node.

Insertion/Creation of BST Rules:
	Left subtree -> values smaller than node
	Right subtree -> values greater than node

	When you insert a value:
		1. Start from root
		2. Compare value with current node
		3. Go:
			left if smaller
			right if larger
		
		4. Repeat until NULL
		5. Insert node there
		
		This process can be done:
			Recursively (most common)
			Iteratively


Deletion Rules:
	Case 1: Node has NO children (Leaf node)
		Just delete it and return NULL.
		
	Case 2: Node has ONE child
		Replace node with its only child (80).

	Case 3: Node has TWO children (MOST IMPORTANT)
		Replace node’s value with:
			Inorder Successor (smallest value in right subtree)
			OR
			Inorder Predecessor (largest in left subtree)
		Most implementations use inorder successor.
		Then:
			Delete that successor node recursively

*/