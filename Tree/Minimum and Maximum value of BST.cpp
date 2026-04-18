
// Minimum and Maximum value of BST

int minValue(TreeNode* root) {
    while (root->left != nullptr)
        root = root->left;
    return root->val;
}

int maxValue(TreeNode* root) {
    while (root->right != nullptr)
        root = root->right;
    return root->val;
}
