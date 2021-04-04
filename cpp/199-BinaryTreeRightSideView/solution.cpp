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
    // O(n)
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> v;
        if (root == NULL) {
            return v;
        }
        traverse(root, v, 0);
        return v;
    }
    
    void traverse(TreeNode* node, std::vector<int> &v, int current_level) {
        if (node == NULL) {
            return;
        }
        // Only take the first of every level
        if (v.size() == current_level) {
            v.push_back(node->val);
        }
        // Priorities nodes on right
        traverse(node->right, v, current_level + 1);
        traverse(node->left, v, current_level + 1);
    }
};