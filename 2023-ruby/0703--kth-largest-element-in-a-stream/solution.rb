class KthLargest

# Category: Heap
# Runtime: O(n log k)
# Note: There was a noted issue with the build-in class.
#       We should try solving this in another language to be sure.

=begin
    :type k: Integer
    :type nums: Integer[]
=end
    def initialize(k, nums)
        @heap = MinHeap.new
        @k = k
        for num in nums
            add(num)
        end
    end

=begin
    :type val: Integer
    :rtype: Integer
=end
    def add(val)
        if @heap.size < @k
            @heap.push(val)
        elsif @heap.next < val
            @heap.pop
            @heap.push(val)
        end
        return @heap.next
    end

end

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest.new(k, nums)
# param_1 = obj.add(val)
#
