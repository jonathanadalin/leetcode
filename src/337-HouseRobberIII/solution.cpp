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
    // O(size of tree) - We only calculate each node's value once.
    // Intermediate operations are constant amortized time O(1).
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
            lower_level_val += rob_dp(root->left->left, m) 
                             + rob_dp(root->left->right, m);
        }
        if (root->right != NULL) {
            lower_level_val += rob_dp(root->right->left, m) 
                             + rob_dp(root->right->right, m);
        }
        // Choose between taking this level or the next.
        int val = max(root->val + lower_level_val,
                      rob_dp(root->left, m) + rob_dp(root->right, m));
        m.insert(make_pair(root, val));
        return val;
    }  
    int rob(TreeNode* root) {
        map<TreeNode*, int> m;
        return rob_dp(root, m);
    }
};