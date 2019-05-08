class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        if (nums.size() < 1) {
            return v;
        }
        v.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            v.push_back(v[i-1] * nums[i-1]);
        }
        int right_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            v[i] *= right_product;
            right_product *= nums[i];
        }
        return v;
    }
};