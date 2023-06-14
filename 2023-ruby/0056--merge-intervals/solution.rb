# @param {Integer[][]} intervals
# @return {Integer[][]}

# Category: Intervals
# Runtime: O(n log n)
def merge(intervals)
    return intervals if intervals.length <= 1

    # O(n log n)
    intervals = intervals.sort_by { |interval| interval.first }

    i = 0
    j = 1
    res = []
    # O(n)
    while j < intervals.length
        if intervals[i].last < intervals[j].first
            res.push(intervals[i])  # O(1)
            i += 1
            j += 1
        else
            # Merge logic
            right = intervals[i].last
            while j < intervals.length && right >= intervals[j].first
                right = [right, intervals[j].last].max
                j += 1
            end
            res.push([intervals[i].first, right])  # O(1)
            i = j
            j += 1
        end
    end
    # Add remaining in O(n)
    while i < j && i < intervals.length
        res.push(intervals[i])  # O(1)
        i += 1
    end
    return res
end

