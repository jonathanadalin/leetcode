class Solution {
public:
    
    vector<vector<int>> res;
    
    void populateRes(vector<int>& candidates, int sum_so_far, int index, vector<int> v, int target) {
        if (index < candidates.size() && sum_so_far <= target) {
            if (sum_so_far + candidates[index] == target) {
                v.push_back(candidates[index]);
                res.push_back(v);
                sum_so_far = 0;
                v.clear();
            } else {
                populateRes(candidates, sum_so_far, index + 1, v, target);                      // Skip this one.
                v.push_back(candidates[index]);
                populateRes(candidates, sum_so_far + candidates[index], index, v, target);      // We can use repeated numbers.
                populateRes(candidates, sum_so_far + candidates[index], index + 1, v, target);  // Take one of it.
            }
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        populateRes(candidates, 0, 0, v, target);
        // No duplicates
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};