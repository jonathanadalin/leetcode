# @param {Integer[]} cost
# @return {Integer}
def min_cost_climbing_stairs(cost)
    return 0 if cost.length <= 1
    return [cost[0], cost[1]].min if cost.length == 2

    one_step_cost = cost[0]
    two_step_cost = cost[1]
    return [one_step_cost + min_cost_climbing_stairs(cost.slice(1, cost.length)), 
            two_step_cost + min_cost_climbing_stairs(cost.slice(2, cost.length))].min
end

