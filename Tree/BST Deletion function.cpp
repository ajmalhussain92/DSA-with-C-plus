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
            root->right = deleteBST (root->right, succ->data);
        }
    }
    return root;
}

/*
Standard BST Deletion:
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