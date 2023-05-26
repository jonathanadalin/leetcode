/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // O(n) since the tree is traversed.
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left != NULL && root->right != NULL) {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        } else if (root->left != NULL) {
            return 1 + maxDepth(root->left);
        } else if (root->right != NULL) {
            return 1 + maxDepth(root->right);
        } else {
            return 1;
        }
    }
};