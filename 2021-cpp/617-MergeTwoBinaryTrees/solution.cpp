class Solution {
public:
    // Linear time: Traversing the intersection of t1 and t2 nodes.
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL && t2 != NULL) {
            TreeNode* t = new TreeNode(t1->val + t2->val);
            t->left = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
            return t;
        } else if (t1 != NULL) {
            return t1;
        } else if (t2 != NULL) {
            return t2;
        } else
            return NULL;
    }
};