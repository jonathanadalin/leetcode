#include <map>

class Solution {
public:
    // O(n)
    int majorityElement(vector<int>& nums) {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if (m[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        return 0;
    }
};