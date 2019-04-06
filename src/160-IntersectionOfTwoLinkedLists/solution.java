/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

import java.util.*;

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        if (headA == null || headB == null) {
            return null;
        }
        
        Vector<ListNode> vA = new Vector<ListNode>();
        ListNode nodeA = headA;
        while (nodeA != null) {
            vA.add(nodeA);
            nodeA = nodeA.next;
        }
        
        Vector<ListNode> vB = new Vector<ListNode>();
        ListNode nodeB = headB;
        while (nodeB != null) {
            vB.add(nodeB);
            nodeB = nodeB.next;
        }
        
        if (vA.get(vA.size() - 1) != vB.get(vB.size() - 1)) {
            return null;
        }
        
        int iA = vA.size() - 2;
        int iB = vB.size() - 2;
        
        while (iA >= 0 && iB >= 0) {
            if (vA.get(iA) == vB.get(iB)) {
                iA--;
                iB--;
            } else {
                break;
            }
        }
        
        return vA.get(iA + 1);
        
    }
}