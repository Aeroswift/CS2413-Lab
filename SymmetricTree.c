/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Recursive helper function that checks if two trees are mirror images
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Case 1: If both nodes are NULL, this part is symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // Case 2: If only one node is NULL, it's not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Case 3: Check three conditions:
    // 1. Values at current nodes must match
    // 2. Left subtree of t1 must mirror right subtree of t2
    // 3. Right subtree of t1 must mirror left subtree of t2
    return (t1->val == t2->val)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
}

// Main function to check if a tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    // An empty tree is symmetric
    if (root == NULL)
        return true;

    // Start recursive comparison on left and right subtrees
    return isMirror(root->left, root->right);
}
