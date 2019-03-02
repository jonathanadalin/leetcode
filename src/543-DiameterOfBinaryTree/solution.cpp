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
    
    int getHeights(TreeNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            node->val = 1 + std::max(getHeights(node->left),
                                     getHeights(node->right));
        }
        return node->val;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        getHeights(root);
        if (root->left != NULL && root->right != NULL) {
            return std::max(root->left->val + root->right->val,
                            std::max(diameterOfBinaryTree(root->left),
                                     diameterOfBinaryTree(root->right)));
        } else if (root->left != NULL) {
            return std::max(diameterOfBinaryTree(root->left), root->left->val);
        } else if (root->right != NULL) {
            return std::max(diameterOfBinaryTree(root->right), root->right->val);
        } else {  // No children
            return 0; 
        }
    }

};