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
        while (node != null) {
            v.add(node.val);
            node = node.next;
        }
        
        if (v.size() < 2) {
            return true;
        }
        
        int i = 0;
        int j = v.size() - 1;
        
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