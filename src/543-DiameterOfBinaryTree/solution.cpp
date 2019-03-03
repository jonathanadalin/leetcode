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
    
    int max_dist;  // Keeps track of the max distance, which is the sum
                   // of heights from left and right branches at a node.
    
    int traverseAndCalcHeights(TreeNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            int l_height = traverseAndCalcHeights(node->left);
            int r_height = traverseAndCalcHeights(node->right);
            max_dist = std::max(max_dist, l_height + r_height);
            return 1 + std::max(l_height, r_height);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        max_dist = 0;
        traverseAndCalcHeights(root);  // Updates <max_dist>.
        return max_dist;
    }
    
};