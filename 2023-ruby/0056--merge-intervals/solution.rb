# @param {Integer[][]} intervals
# @return {Integer[][]}

# Category: Intervals
# Runtime: O(n log n)
# Notes: Key elements here are starting a array to build the result and sorting
#        with sort_by.
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
            # No overlap, just just add the element to the result.
            res.push(intervals[i])  # O(1)
            i += 1
            j += 1
        else
            # Merge viable intervals and add them to the result.
            # We must consider the growing interval by growing the right
            # boundary of the interval.
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
    # We should check for a remaining interval since i = j - 1
    res.push(intervals[i]) if i < intervals.length  # O(1)
    return res
end

