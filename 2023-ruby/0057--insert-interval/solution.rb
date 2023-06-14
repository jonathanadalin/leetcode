# @param {Integer[][]} intervals
# @param {Integer[]} new_interval
# @return {Integer[][]}
def insert(intervals, new_interval)
    i = 0
    # Just insert it for now
    # O(n)
    if intervals.empty?
        intervals.push(new_interval)
    else
        while i <= intervals.length
            if intervals[i].first > new_interval.first
                intervals.insert(i, new_interval)
                break
            end
            if i == intervals.length - 1
                intervals.insert(intervals.length, new_interval)
                break
            end
            i += 1
        end
    end

    # Now merge
    # O(n^2) - yikes
    i = 0
    while i < intervals.length - 1
        if intervals[i].last >= intervals[i + 1].first
            intervals[i][1] = [intervals[i].last, intervals[i + 1].last].max
            intervals.delete_at(i + 1) # O(n)
        else
            i += 1
        end
    end
    return intervals
end

