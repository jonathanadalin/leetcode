class Solution {
public:
    // O(n) - We perform 2 passes of nums
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        if (nums.size() < 1) {
            return v;
        }
        // Calculate the products left of each element
        // and save them in place for later.
        v.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            v.push_back(v[i-1] * nums[i-1]);
        }
        // Calculate the products right of each element.
        // We need an additional variable so we don't
        // lose our progress.
        int right_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            v[i] *= right_product;
            right_product *= nums[i];
        }
        return v;
    }
};