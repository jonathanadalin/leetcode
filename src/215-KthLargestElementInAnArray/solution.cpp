class Solution {
public:
    // O(nlog(n)) - The sort is the algorithm bottleneck.
    int findKthLargest(vector<int>& nums, int k) {
        if (k - 1 > nums.size()) {
            return -1;
        }
        auto comp = [](int a, int b) {
            return a > b;
        };
        sort(nums.begin(), nums.end(), comp);
        return nums[k - 1];
    }
};