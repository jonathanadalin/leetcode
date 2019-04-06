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
        
        Vector<Integer> vA = new Vector<Integer>();
        ListNode nodeA = headA;
        while (nodeA != null) {
            vA.add(nodeA.val);
            nodeA = nodeA.next;
        }
        
        Vector<Integer> vB = new Vector<Integer>();
        ListNode nodeB = headB;
        while (nodeB != null) {
            vB.add(nodeB.val);
            nodeB = nodeB.next;
        }
        
        if (vA.get(vA.size() - 1).intValue() != vB.get(vB.size() - 1).intValue()) {
            return null;
        }
        
        int iA = vA.size() - 1;
        int iB = vB.size() - 1;
        
        while (iA >= 0 && iB >= 0) {
            if (vA.get(iA).intValue() == vB.get(iB).intValue()) {
                iA--;
                iB--;
            } else {
                break;
            }
        }
        
        ListNode intersectNode = headA;
        for (int i = 0; i <= iA; i++) {
            intersectNode = intersectNode.next;
        }
        
        return intersectNode;
    }
}