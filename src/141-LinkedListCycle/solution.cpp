/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    // O(n)
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;            
        }
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        while (fast_ptr != NULL && slow_ptr != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            if (fast_ptr != NULL) {
                fast_ptr = fast_ptr->next;
            } else {
                break;
            }
            if (slow_ptr == fast_ptr) {
                return true;
            }
        }
        return false;
    }
};