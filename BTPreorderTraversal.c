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

// Recursive helper function to perform preorder traversal
void helper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;  // Base case: do nothing if node is NULL

    result[(*index)++] = root->val;  // Visit root: store current node's value in result and increment index
    helper(root->left, result, index);  // Recursively traverse left subtree
    helper(root->right, result, index); // Recursively traverse right subtree
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;  // Initialize the return size to 0

    // Allocate memory for result array (max 100 nodes as per constraints)
    int* result = (int*)malloc(sizeof(int) * 100);

    int index = 0;  // Index tracks where to insert next value in result array
    helper(root, result, &index);  // Start preorder traversal from root
    *returnSize = index;  // Set returnSize to total number of visited nodes

    return result;  // Return the filled result array
}
