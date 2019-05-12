class Solution {
public:
    
    vector<vector<int>> res;
    
    void populateRes(vector<int>& candidates, int sum_so_far, int index,
                     vector<int> v, int target) {
        if (index < candidates.size() && sum_so_far + candidates[index] <= target) {
            if (sum_so_far + candidates[index] == target) {
                v.push_back(candidates[index]);
                res.push_back(v);
            } else {
                // Skip this one.
                populateRes(candidates, sum_so_far, index + 1, v, target);  
                v.push_back(candidates[index]);
                // We can use repeated numbers.
                populateRes(candidates, sum_so_far + candidates[index],
                            index, v, target);
                // Take one of it.
                populateRes(candidates, sum_so_far + candidates[index],
                            index + 1, v, target);  
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