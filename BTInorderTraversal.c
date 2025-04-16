/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Recursive helper function to perform inorder traversal
void helper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;  // Base case: if the node is NULL, do nothing

    helper(root->left, result, index);       // First, recursively traverse the left subtree
    result[(*index)++] = root->val;          // Then visit the root: store value and move index forward
    helper(root->right, result, index);      // Finally, recursively traverse the right subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;  // Initialize the return size to 0

    // Allocate space for up to 100 nodes (as per constraints)
    int* result = (int*)malloc(sizeof(int) * 100);

    int index = 0;  // Tracks the current position in the result array
    helper(root, result, &index);  // Start traversal from the root
    *returnSize = index;  // Store total number of visited nodes

    return result;  // Return the array containing inorder traversal
}
