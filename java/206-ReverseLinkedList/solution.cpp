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
        var node = head;
        while (node != null) {
            list.add(node);
            node = node.next;
        }
        for (var i = 0; i < list.size(); i++) {
            node = list.get(i);
            if (i == 0) {
                node.next = null;
            } else {
                node.next = list.get(i - 1);
            }
        }
        return list.get(list.size() - 1);
    }
}
