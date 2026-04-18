Node* insertBST (Node* root, int val) {
    // Base case: found position
    if (root == nullptr) return new Node (val);

    if (val < root->data) {
        root->left = insertBST (root->left, val);
    } 
    else if (val > root->data) {
        root->right = insertBST (root->right, val);
    }

    // If val == root->data, ignore duplicates (or handle separately)
    return root;
}
/*
Standard BST Insertion:
	1. Start from the root
	2. Compare value with current node
	3. Go:
			left if smaller
			right if larger
	4. Repeat until NULL
	5. Insert node there
*/