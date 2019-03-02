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
    
    int getBranchHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            return 1 + std::max(getBranchHeight(node->left),
                                getBranchHeight(node->right));
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left != NULL && root->right != NULL) {
            return std::max(getBranchHeight(root->left) + getBranchHeight(root->right),
                            std::max(diameterOfBinaryTree(root->left),
                                     diameterOfBinaryTree(root->right)));
        } else if (root->left != NULL) {
            return std::max(diameterOfBinaryTree(root->left),
                            getBranchHeight(root->left));
        } else if (root->right != NULL) {
            return std::max(diameterOfBinaryTree(root->right),
                            getBranchHeight(root->right));
        } else {  // No children
            return 0; 
        }
    }

};