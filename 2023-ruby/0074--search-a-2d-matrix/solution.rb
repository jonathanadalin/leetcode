# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}

# Category: Binary search
# Runtime: O(log mn)
def search_matrix(matrix, target)
    array = []
    for row in matrix
        array.concat(row)
    end
    return search_array(array, target, 0)
end

def search_array(array, target, index)
    return false if array.length == 0
    return array.first == target if array.length == 1

    middle = array.length / 2
    left = array.slice(0, middle)
    right = array.slice(middle, array.length)

    if target < array[middle]
        search_array(left, target, index)
    elsif target > array[middle]
        search_array(right, target, index + middle)
    else
        return true
    end
end

