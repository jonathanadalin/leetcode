class Solution {
public:
    // O(n) with n being the number of digits in x or y's binary representation.
    int hammingDistance(int x, int y) {
        int count = 0;
        int num_binary_digits;
        if (x == y) {
            return 0;
        }
        if (x > y) {
            num_binary_digits = floor(log(x) / log(2)) + 1;
        } else {
            num_binary_digits = floor(log(y) / log(2)) + 1;
        }
        int i = num_binary_digits - 1;
        int n;
        while (i >= 0) {
            n = pow(2, i);
            if (x - n >= 0 && y- n >= 0) {
                x -= n;
                y -= n;
            } else if (x - n >= 0 && y - n < 0) {
                count++;
                x -= n;
            } else if (y - n >= 0 && x - n < 0){
                count++;
                y -= n;
            }
            i--;
        }
        return count;
    }
};