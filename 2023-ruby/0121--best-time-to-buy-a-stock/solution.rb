# @param {Integer[]} prices
# @return {Integer}

# Category: Sliding Window
# Runtime: O(n)
def max_profit(prices)
    past = 0
    future = 1
    max = 0
    while future < prices.length
        past = future if prices[future] < prices[past]  # Slide the window forward
        net = prices[future] - prices[past]
        if  net > max
            max = net
        else
            future += 1
        end
    end
    return max
end

