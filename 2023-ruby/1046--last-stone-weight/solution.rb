# @param {Integer[]} stones
# @return {Integer}

# Category: Heap / Priority queue
# Runtime: O(n log n)
def last_stone_weight(stones)
    heap = MaxHeap.new(stones)
    while heap.size > 1
        remaining = heap.pop - heap.pop # O(log n)
        heap.push(remaining)  # O(log n)
    end
    return heap.pop
end

