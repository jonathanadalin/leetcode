class Solution {
public:

    // O(n)
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 0) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            // Since we are iterating using values as indexes,
            // they will cross within the cycle that is created
            // by the duplicate value.
            while (fast != slow) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            // Fast and slow have met in the circle.
            // If we reset fast, and go a slow's pace
            // They'll meet at the circle entrance, which
            // is the duplicate value.
            fast = 0;
            while (fast != slow) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return fast;
        }
        return -1;
    }

    // O(n)
    int findDuplicateWithSet(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return num;
            }
        }
        return -1;
    }
};