# @param {Integer[]} cost
# @return {Integer}

# Category: Dynamic programming
# Runtime: O(n)
def min_cost_climbing_stairs(cost)
    dp = Array.new(cost.length)
    for i in 0...cost.length
        if i < 2
            dp[i] = cost[i] 
        else
            dp[i] = cost[i] + [dp[i - 1], dp[i - 2]].min
        end
    end
    return [dp[cost.length - 1], dp[cost.length - 2]].min
end

def min_cost_climbing_stairs_recursive(cost)
    return 0 if cost.length < 2
    return [cost[0], cost[1]].min if cost.length == 2

    one_step_cost = cost[0]
    two_step_cost = cost[1]
    return [one_step_cost + min_cost_climbing_stairs(cost.slice(1, cost.length)), 
            two_step_cost + min_cost_climbing_stairs(cost.slice(2, cost.length))].min
end

