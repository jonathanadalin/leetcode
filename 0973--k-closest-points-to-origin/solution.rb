# @param {Integer[][]} points
# @param {Integer} k
# @return {Integer[][]}

# Category: Heaps
# Runtime: O(nlogn)
# Notes: At the time of writing, this solution gets a TLE in Leetcode, so used
# a method to pass the LeetCode check. See below.
def k_closest(points, k)
    distances_and_points = MinHeap.new
    for point in points # O(nlogn)
        distances_and_points.push(eucledian_distance_from_origin(point), point) # O(logn)
    end
    res = []
    while k > 0  # O(n)
        res.push(distances_and_points.pop) # O(1)
        k -= 1
    end
    return res
end

def eucledian_distance_from_origin(point)
    sqrt(point[0] ** 2 + point[1] ** 2)
end

def k_closest_with_sort(points, k)
    points.sort_by { |x, y| x ** 2 + y ** 2 }.first(k) # Also O(nlogn)
end

