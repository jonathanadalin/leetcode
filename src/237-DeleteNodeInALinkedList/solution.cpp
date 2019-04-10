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
    // We don't have access to the head, so just go through all the nodes
    // after the one we have to delete and copy their values.
    // O(n) at worst, we go through the whole list at worst.
    void deleteNode(ListNode* node) {
        while (node->next != NULL) {  // There is at least 2 nodes.
            node->val = node->next->val;
            if (node->next->next == NULL) {  // The next node is at the end.
                node->next = NULL;
            } else {
                node = node->next;
            }
        }
    }
};