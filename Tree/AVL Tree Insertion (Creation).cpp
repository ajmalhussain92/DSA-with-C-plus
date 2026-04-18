#include <iostream>
#include <queue>
using namespace std;

// AVL Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node (int val) {
        data = val;
        left = right = nullptr;
        height = 1;         // new node is always height 1
    }
};

// Height helper function
int getHeight (Node* root) {
    if (root == nullptr) return 0;
    return root->height;
}

// Balance Factor
int getBalance (Node* root) {
    if (root == nullptr) return 0;
    return getHeight (root->left) - getHeight (root->right);
}

// Right Rotation (LL case)
Node* rightRotate (Node* y) {
    Node* x = y->left;
    Node* T2 = x->right; 

    // Rotate
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max (getHeight (y->left), getHeight (y->right)) + 1;
    x->height = max (getHeight (x->left), getHeight (x->right)) + 1;

    return x; // new root
}

// Left Rotation (RR case) 
Node* leftRotate (Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    // Rotate
    x->left = y;
    y->right = T2;

    // Update heights
    y->height = max (getHeight (y->left), getHeight (y->right)) + 1;
    x->height = max (getHeight (x->left), getHeight (x->right)) + 1;

    return x; // new root
}

// AVL insertion = BST insertion + height update + balance check + rotation (if needed)
Node* insertAVL (Node* root, int val) {
    // 1. Normal BST insertion
    if (root == nullptr) return new Node (val);		// immediately returns after inserting very first node
    
    if (val < root->data) 
        root->left = insertAVL (root->left, val);

    else if (val > root->data) 
        root->right = insertAVL (root->right, val);
    
    else
        return root;        // duplicates not allowed
    
    // 2. Update height		(after insertion, deletion, or rotations)
    root->height = 1 + max (getHeight (root->left), getHeight (root->right));	// updates along the path from leaf up to the root.
    
    // 3. Get balance factor
    int balance = getBalance (root);
    
    // 4. 4 Rotation cases

    // LL case
    if (balance > 1 && val < root->left->data) return rightRotate (root);
    
    // RR case
    if (balance < -1 && val > root->right->data) return leftRotate (root);
    
    // LR case
    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate (root->left);
        return rightRotate (root);
    }

    // RL case
    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate (root->right);
        return leftRotate (root);
    }
     
    // 5. Return unchanged root
    return root;
}

// Level-order Traversal (for verification)
void levelorder (Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push (root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";
        
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
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
    
    // Make AVL Tree
    root = insertAVL (root, 4);
    root = insertAVL (root, 6);
    root = insertAVL (root, 8);
    root = insertAVL (root, 12);
    root = insertAVL (root, 20);
    
    //
    cout << "\nLevel Order Traversal: ";
    levelorder (root);
    
    cout << "\nInorder Traversal: ";
    inorder (root);

    return 0;
}

/*
Standard AVL Insertion:
	1. Perform Standard BST Insertion
	2. Update Heights During Backtracking
	3. Check Balance Factors and Rebalance
	4. Perform Rotations Based on the Case
	
The balance factor is independent of the node's own height

*/