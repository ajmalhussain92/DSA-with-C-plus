#include <iostream>
using namespace std;

// BST Insertion & Deletion

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

// Insertion
Node* insertBST (Node* root, int val) {
    // Base case: found position
    if (root == nullptr) {
        return new Node (val);
    }

    if (val < root->data) {
        root->left = insertBST (root->left, val);
    } 
    else if (val > root->data) {
        root->right = insertBST (root->right, val);
    }

    // If val == root->data, ignore duplicates (or handle separately)
    return root;
}

// Deletion
Node* deleteBST (Node* root, int key) {
    // Base case
    if (root == nullptr) return nullptr;

    // Step 1: Search for the node
    if (key < root->data) {
        root->left = deleteBST (root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteBST (root->right, key);
    }
    else {
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
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            // Find inorder successor (min in right subtree)
            Node* succ = root->right;
            while (succ->left != nullptr) {
                succ = succ->left;
            }

            // Copy successor's value
            root->data = succ->data;

            // Delete successor node
            root->right = deleteBST(root->right, succ->data);
        }
    }
    return root;
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

    int values[] = {50, 30, 70, 20, 60, 80};
    int n = sizeof (values) / sizeof (values[0]);

    for (int i = 0; i < n; i++) {
        root = insertBST (root, values[i]);
    }

    cout << "BST created successfully!\n";
    
    cout << "\nInorder Traversal: ";
    inorder (root);
    
    deleteBST (root, 70);
    
    cout << "\nInorder Traversal: ";
    inorder (root);
    
    return 0;
}