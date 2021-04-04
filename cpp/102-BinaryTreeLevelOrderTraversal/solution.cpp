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
    // O(n) - We traverse through all the notes
    // and intermediate operations are O(1).
    // The solution is modified DF traversal with count
    // to keep track of what level we're on.
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> v;
        int count = 0;
        int nodes_this_level = 1;
        int nodes_next_level = 0;
        while(root != NULL) {
            if (root->left != NULL) {
                nodes_next_level++;
                q.push(root->left);
            }
            if (root->right != NULL) {
                nodes_next_level++;
                q.push(root->right);
            }
            v.push_back(root->val);
            count++;
            if (count == nodes_this_level) {
                res.push_back(v);
                v.clear();
                count = 0;
                nodes_this_level = nodes_next_level;
                nodes_next_level = 0;
            }
            if (!q.empty()) {
                root = q.front();
                q.pop();
            } else {
                root = NULL;
            }
        }
        return res;
    }
};