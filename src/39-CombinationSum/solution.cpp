class Solution {
public:
        
    void populateRes(const vector<int>& candidates, int index,
                     vector<int> &v, int target, vector<vector<int>>& res) {
        if (index < candidates.size() && candidates[index] <= target) {
            if (candidates[index] == target) {
                v.push_back(candidates[index]);
                res.push_back(v);
                v.pop_back();
            } else {
                // Branch off with the next candidate.
                populateRes(candidates, index + 1, v, target, res);
                // We can use repeated numbers.
                v.push_back(candidates[index]);
                populateRes(candidates, index, v, target - candidates[index], res);
                v.pop_back();
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