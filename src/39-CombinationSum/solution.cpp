class Solution {
public:
        
    void populateRes(const vector<int>& candidates, int index,
                     vector<int> v, int target, vector<vector<int>>& res) {
        if (index < candidates.size() && candidates[index] <= target) {
            if (candidates[index] == target) {
                v.push_back(candidates[index]);
                res.push_back(v);
            } else {
                // Go to the next value.
                populateRes(candidates, index + 1, v, target, res);  
                v.push_back(candidates[index]);
                // We can use repeated numbers.
                populateRes(candidates, index, v, target - candidates[index], res);
            }
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        populateRes(candidates, 0, v, target, res);
        return res;
    }
    
};