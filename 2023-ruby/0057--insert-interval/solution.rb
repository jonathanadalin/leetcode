# @param {Integer[][]} intervals
# @param {Integer[]} new_interval
# @return {Integer[][]}

# Category: Intervals
# Runtime: O(n) - Single pass with O(1) operations
def insert(intervals, new_interval)
    i = 0
    result = []
    # The result should match the original intervals until the new interval is relevant
    while(i < intervals.size && intervals[i].last < new_interval.first)
        result.push(intervals[i])
        i += 1
    end
    # Build the new interval then add it
    first, last = 0, 0
    while(i < intervals.size && intervals[i].first <= new_interval.last)
        new_interval[0] = [intervals[i].first, new_interval.first].min
        new_interval[1] = [intervals[i].last, new_interval.last].max
        i += 1
    end
    result.push(new_interval)
    # Just add the rest
    while(i < intervals.size)
        result.push(intervals[i])
        i += 1
    end
    return result
end

