/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    
    // O(n) - We need to place all the values of nums
    //        into the BST.

    public TreeNode sortedArrayToBSTIterative(int[] nums) {
        
        if (nums == null) {
            return null;
        }
        
        if (nums.length == 0) {
            return null;
        }
        
        Stack<Object> s = new Stack<Object>();
        // We're going to overwrite this value later.
        TreeNode root = new TreeNode(0);
        s.push(root);
        s.push(0);
        s.push(nums.length);
        
        while (!s.empty()) {
            
            int right = (int) s.pop();
            int left = (int) s.pop();
            TreeNode n = (TreeNode) s.pop();
            
            int mid = (left + right) / 2;
            if (mid >= 0 && mid < nums.length) {
                n.val = nums[mid];
            }
            
            if (left < mid) {
                n.left = new TreeNode(0);
                s.push(n.left);
                s.push(left);
                s.push(mid);
            }
            
            if (right > mid + 1) {
                n.right = new TreeNode(0);
                s.push(n.right);
                s.push(mid + 1);
                s.push(right);
            }
            
        }
        
        return root;

    }
    
    public TreeNode sortedArrayToBSTRecursive(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        return helper(nums, 0, nums.length);
    }
    
    public TreeNode helper(int[] nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            TreeNode n = new TreeNode(nums[mid]);
            n.left = helper(nums, left, mid);
            n.right = helper(nums, mid + 1, right);
            return n;
        } else {
            return null;
        }
    }
}