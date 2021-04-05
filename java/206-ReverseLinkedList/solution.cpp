/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 // This is pretty slow O(n^2), but it's a start...
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }
        var node = head;
        while (node.next != null && node.next.next != null) {
            node = node.next;
        }
        var val = node.next.val;
        node.next = null;
        return new ListNode(val, reverseList(head));
    }
}
