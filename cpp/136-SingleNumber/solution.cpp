#include <map>

class Solution {
public:
    // Runtime: O(n) 
    int singleNumber(vector<int>& nums) {
        // Per problem description, <nums> must contain a single value.
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a ^= nums[i];
        }
        return a;
    }
};