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

// Runtime is O(2n), one pass to build the array list, then a pass of that
// list to build the reverse list.
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }
        var list = new ArrayList<ListNode>();
        while (head != null) {
            list.add(head);
            head = head.next;
        }
        // Build the inverse list.
        for (var i = 0; i < list.size(); i++) {
            head = list.get(i);
            if (i == 0) {
                head.next = null;
            } else {
                head.next = list.get(i - 1);
            }
        }
        // The tail of the list is the head of the inverse list.
        return list.get(list.size() - 1);
    }
}

