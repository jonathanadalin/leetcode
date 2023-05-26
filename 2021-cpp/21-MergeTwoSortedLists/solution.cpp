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
    // O(m + n)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l;
        ListNode* head;
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 != NULL && l2 == NULL) {
            return l1;
        } else if (l1 == NULL && l2 != NULL) {
            return l2;
        }
        if (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                l = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                l = new ListNode(l2->val);   
                l2 = l2->next;
            }
            head = l;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                l->next = new ListNode(l2->val);   
                l2 = l2->next;
            }
            l = l->next;
        }
        if (l1 != NULL) {
            l->next = l1;
        }
        if (l2 != NULL) {
            l->next = l2;
        }      
        return head;
    }
};