class Solution {
public:
    
    void subsets_recursive(const vector<int> &nums, int current,
                           vector<int> v, vector<vector<int>> &res) {
        for (int i = current; i < nums.size(); i++) {
            v.push_back(nums[i]);
            res.push_back(v);
            subsets_recursive(nums, i + 1, v, res);
            v.erase(v.end() - 1);
        }
    }
    
    // O(size of res) - Every recursive call pushes to res.
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        subsets_recursive(nums, 0, v, res);
        return res;
    }
};