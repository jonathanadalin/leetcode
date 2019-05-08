class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        for (int num : nums) {
            product *= num;
        }
        vector<int> v;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            v.push_back(product / *it);
        }
        return v;
    }
};