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
    // O(n^2)
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return pathSumFrom(root, sum)  // O(n)
               + pathSum(root->left, sum) 
               + pathSum(root->right, sum);
    }
    // O(n)
    int pathSumFrom(TreeNode* node, int sum) {
        if (node == NULL) {
            return 0;
        }
        return (node->val == sum ? 1 : 0)
               + pathSumFrom(node->left, sum - node->val)
               + pathSumFrom(node->right, sum - node->val);
    }
};