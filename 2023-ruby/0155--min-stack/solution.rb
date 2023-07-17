# Category: Stack
# Runtime: All functions are O(1)

class MinStack
    def initialize()
       @stack = []
       @min = []
    end


=begin
    :type val: Integer
    :rtype: Void
=end
    def push(val)
        @stack.push(val)
        @min.push(val) if @min.empty? || val <= @min.last
    end


=begin
    :rtype: Void
=end
    def pop()
        val = @stack.pop
        @min.pop if @min.last == val
    end


=begin
    :rtype: Integer
=end
    def top()
        @stack.last
    end


=begin
    :rtype: Integer
=end
    def get_min()
        return @min.last
    end


end

# Your MinStack object will be instantiated and called as such:
# obj = MinStack.new()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.get_min()

