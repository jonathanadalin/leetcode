class Solution {
public:
    // O(n)
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int fib = 0;
        int fib_a = 1;
        int fib_b = 1;
        for (int i = 2; i < n + 1; i++) {
            fib = fib_a + fib_b;
            fib_a = fib_b;
            fib_b = fib;
        }
        
        return fib;
        
    }
};