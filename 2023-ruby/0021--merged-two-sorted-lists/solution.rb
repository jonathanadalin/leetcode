# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} list1
# @param {ListNode} list2
# @return {ListNode}

# Category: Linked Lists
# Runtime: O(n + m)
def merge_two_lists(list1, list2)
    return nil if list1 == nil && list2 == nil
    return list1 if list2 == nil
    return list2 if list1 == nil

    head = ListNode.new
    curr = head
    while list1 != nil && list2 != nil
        if list1.val < list2.val
            curr.val = list1.val
            curr.next = ListNode.new
            curr = curr.next
            list1 = list1.next
        else
            curr.val = list2.val
            curr.next = ListNode.new
            curr = curr.next
            list2 = list2.next
        end
    end
    while list1 != nil
        curr.val = list1.val
        curr.next = ListNode.new unless list1.next == nil
        curr = curr.next
        list1 = list1.next
    end
    while list2 != nil
        curr.val = list2.val
        curr.next = ListNode.new unless list2.next == nil
        curr = curr.next
        list2 = list2.next
    end
    return head
end

