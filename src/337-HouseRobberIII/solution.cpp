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
    
    int rob_dp(TreeNode* root, map<TreeNode*, int>& m) {
        if (root == NULL) {
            return NULL;
        }
        // Don't recurse if we already found the value before.
        auto it = m.find(root);
        if (it != m.end()) {
            return (*it).second;
        }
        int lower_level_val = 0;
        if (root->left != NULL) {
            lower_level_val += rob_dp(root->left->left, m) + rob_dp(root->left->right, m);
        }
        if (root->right != NULL) {
            lower_level_val += rob_dp(root->right->left, m) + rob_dp(root->right->right, m);
        }
        // Choose between taking this level or the next.
        int val = max(root->val + lower_level_val, rob_dp(root->left, m) + rob_dp(root->right, m));
        m.insert(make_pair(root, val));
        return val;
    }
    
    int rob_dp(TreeNode* root) {
        map<TreeNode*, int> m;
        return rob_dp(root, m);
    }

    // Less optimal solution below...

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