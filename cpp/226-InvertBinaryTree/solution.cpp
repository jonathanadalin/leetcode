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
    // O(n) since we're going through every node
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        } else if (root->left != NULL && root->right != NULL) {
                TreeNode* temp = root->left;
                root->left = invertTree(root->right);
                root->right = invertTree(temp);
            
        } else if (root->left != NULL) {
            root->right = invertTree(root->left);
            root->left = NULL;
        } else if (root->right != NULL) {
            root->left = invertTree(root->right);
            root->right = NULL;
        }
        return root;  // Don't need to do anything.
    }
};