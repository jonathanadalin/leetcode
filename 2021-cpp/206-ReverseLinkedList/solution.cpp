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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev;
        ListNode* curr = head;
        ListNode* next = next = curr->next;
        curr->next = NULL;
        while (next != NULL) {
            prev = curr;
            curr = next;
            next = next->next;   
            curr->next = prev;
        }
        return curr;
    }
};