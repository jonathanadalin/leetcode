# @param {Integer} n
# @return {Integer}

# Category: Dynamic programming
# Runtime: O(n)

# Step 1: Come up with the intuitive recursive solution.
def climb_stairs_recursive(n)
    # Establish the base case.
    return 0 if n <= 0
    return 1 if n == 1
    return 2 if n == 2

    # This isn't very efficient.
    return climb_stairs(n - 1) + climb_stairs(n - 2)
end

# Step 2: Come up with memoize optimization.
def climb_stairs_memoize(n)
    # Use a map to save from recalculating in recursion.
    # The initial map values are the base case values from step 1.
    map = {}
    map[0] = 0
    map[1] = 1
    map[2] = 2

    # We use a for loop instead of recursion now.
    for i in 3..n
        map[i] = map[i - 1] + map[i - 2]
    end

    return map[n]
end

# Step 3: Optimize by replacing the map with variables.
def climb_stairs(n)
    # Notice we have the same base cases again.
    steps_minus_2 = 1
    steps_minus_1 = 2
    return steps_minus_2 if n == 1
    return steps_minus_1 if n == 2

    # We still use a for loop.
    current_step = 0
    for i in 3..n
        current_steps = steps_minus_1 + steps_minus_2
        
        # We must anticipate for the next iteration because we 
        # no longer have the luxury of storing our results.
        steps_minus_2 = steps_minus_1
        steps_minus_1 = current_steps
    end
    return current_steps
end

