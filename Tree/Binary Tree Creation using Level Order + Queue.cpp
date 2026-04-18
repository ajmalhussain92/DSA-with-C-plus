#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Creation using Level Order + Queue: Nodes are created "level-by-level"

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

Node* buildTreeLevelOrder () {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;
	
	// Base case
    if (val == -1) return nullptr;
	
	// Create current node
    Node* root = new Node (val);
    queue<Node*> q;
    q.push (root);

    while (!q.empty ()) {
        Node* curr = q.front ();
        q.pop ();

        int leftVal, rightVal;

        // Left child
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node (leftVal);
            q.push (curr->left);
        }

        // Right child
        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node (rightVal);
            q.push (curr->right);
        }
    }

    return root;
}

// Level order traversal (for verification)
void levelOrder (Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push (root);

    while (!q.empty ()) {
        Node* curr = q.front ();
        q.pop ();
		
        cout << curr->data << " ";
		
        if (curr->left) q.push (curr->left);		// letf node	(check if any)
        if (curr->right) q.push (curr->right);		// right node	(check if any)
    }
}

// Preorder traversal (for verification)
void preorder (Node* root) {
    if (!root) return;
    
    cout << root->data << " ";
    preorder (root->left);
    preorder (root->right);
}

int main () {
    Node* root = buildTreeLevelOrder ();

    cout << "\nLevel Order Traversal: ";
    levelOrder (root);
    
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

Queue ensures level-by-level construction

Level Order Traversal: 10, 20, 30, 40, 50

*/