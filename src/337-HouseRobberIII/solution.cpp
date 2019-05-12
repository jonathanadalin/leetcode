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
    
    int rob(TreeNode* root, bool just_robbed) {
        if (root == NULL) {
            return 0;
        }
        if (just_robbed) {
            return (rob(root->left, false) + rob(root->right, false));               // Must skip over this house
        } else {
            // You have a choice...
            return (max(root->val + rob(root->left, true) + rob(root->right, true),  // Rob current house
            rob(root->left, false) + rob(root->right, false)));                      // Rob next house
        }
    }
    
    int rob(TreeNode* root) {
        return rob(root, false);
    }
};