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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        int node_count = 0;
        int nodes_without_null;
        bool reach_end = false;
        while (root != NULL) {
            if (root->left != NULL) {
                node_count++;
                q.push(root->left);
            } else {
                if (!reach_end) {
                    reach_end = true;
                    nodes_without_null = node_count;
                }
            }
            if (root->right != NULL) {
                node_count++;
                q.push(root->right);
            } else {
                if (!reach_end) {
                    reach_end = true;
                    nodes_without_null = node_count;
                }
            }
            if (!q.empty()) {
                root = q.front();
                q.pop();
            } else {
                root = NULL;
            }
        }
        return node_count == nodes_without_null;
    }
};