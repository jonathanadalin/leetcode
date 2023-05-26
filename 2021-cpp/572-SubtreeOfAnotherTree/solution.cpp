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
    
    // O(n*m) : We perform isSameTree on each node of s.
    // n is the size of s
    // m is the size of t
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        if (isSameTree(s, t)) {
            return true;
        } else {
            return (isSubtree(s->left, t) || isSubtree(s->right, t));
        }
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        } else if (s == NULL || t == NULL) {
            return false;
        }
        if (s->val == t->val) {
            return (isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
        } else {
            return false;
        }
    }
        
};