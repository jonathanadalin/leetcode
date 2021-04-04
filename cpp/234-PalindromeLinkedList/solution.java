/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.*;

class Solution {
    public boolean isPalindrome(ListNode head) {
        Vector<Integer> v = new Vector<Integer>();
        ListNode node = head;
        
        // O(n)
        while (node != null) {
            v.add(node.val);
            node = node.next;
        }
        
        if (v.size() < 2) {
            return true;
        }
        
        int i = 0;
        int j = v.size() - 1;
        
        // O(n/2)
        while (i < j) {
            if (v.get(i).intValue() != v.get(j).intValue()) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}