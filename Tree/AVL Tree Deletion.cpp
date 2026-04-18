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

// AVL delete function
Node* deleteAVL (Node* root, int key) {
    if (root == nullptr) return nullptr;

    // Search for the node
    if (key < root->data) {
        root->left = deleteAVL (root->left, key);
    } else if (key > root->data) {
        root->right = deleteAVL (root->right, key);
    } else {
        // Node found

        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        // Case 3: Two children
        else {
            Node* succ = root->right;
            while (succ->left != nullptr) {
                succ = succ->left;
            }
            root->data = succ->data;
            root->right = deleteAVL (root->right, succ->data);
        }
    }

    if (root == nullptr) return root;

    // Update height
    root->height = 1 + max (getHeight (root->left), getHeight (root->right));

    // Get balance factor
    int balance = getBalanceFactor (root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor (root->left) >= 0)
        return rotateRight (root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor (root->left) < 0) {
        root->left = rotateLeft (root->left);
        return rotateRight (root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor (root->right) <= 0)
        return rotateLeft (root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor (root->right) > 0) {
        root->right = rotateRight (root->right);
        return rotateLeft (root);
    }

    return root;
}

/*

After Deletion:
	1. Update the node's height
	2. Compute the balance factor
	3. Perform rotations if needed

*/