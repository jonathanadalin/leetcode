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
    public TreeNode sortedArrayToBST(int[] nums) {
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