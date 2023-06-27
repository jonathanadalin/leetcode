# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {ListNode}

# Category: Linked List
# Runtime: O(n)
def reverse_list(head)
    curr = head
    prev = nil
    while curr != nil
        nextt = curr.next
        curr.next = prev
        prev = curr
        curr = nextt        
    end
    return prev
end

