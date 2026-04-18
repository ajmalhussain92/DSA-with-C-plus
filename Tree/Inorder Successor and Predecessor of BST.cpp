// Inorder Successor and Predecessor in Inorder traversal of BST
// Inorder traversal (Left -> Root -> Right) of a Binary Search Tree (BST) always produces a sorted sequence

long long prev = LLONG_MIN;

bool inorder (TreeNode* root) {
    if (!root) return true;

    if (!inorder (root->left)) return false;

    if (root->val <= prev) return false;
    prev = root->val;

    return inorder (root->right);
}

/*
Binary Tree:

          20
         /  \
       10    30
      /  \     \
     5   15     40

To find out Inorder Successor and Predecessor, do first Inorder Traversal.
Inorder Traversal: 5 10 15 20 30 40				(sorted sequence)

For any node:
	Successor = Minimum of right subtree		(The smallest value in the node’s right subtree)
	Predecessor = Maximum of left subtree		(The largest value in the node’s left subtree)

*/