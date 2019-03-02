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
    
    void traverseAndUpdate(TreeNode* node, int& sum) {
        if (node != NULL) {
            traverseAndUpdate(node->right, sum);
            node->val += sum;
            sum = node->val;
            traverseAndUpdate(node->left, sum);
        }

    }
    
    TreeNode* convertBST(TreeNode* root) { 
        if (root == NULL) {
            return NULL;
        }
        int sum = 0;
        traverseAndUpdate(root, sum);
        return root;
    }

};