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

    // O(n) - We go through the tree once, stack calls are O(1).
    vector<int> inorderTraversal_iter(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        while (root != NULL || !s.empty()) {
            while (root != NULL) {
                s.push(root);
                root = root->left;     
            }
            root = s.top();  // Stack elements are not NULL.
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }

    // O(n) - We go through the tree once.
    vector<int> v;
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        
        if (root != NULL) {
            inorderTraversal(root->left);
            v.push_back(root->val);
            inorderTraversal(root->right);
        }
        
        return v;
    }
};