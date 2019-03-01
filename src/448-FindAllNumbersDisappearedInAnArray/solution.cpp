class Solution {
public:

    // O(n)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // O(n)
        int j;
        for (int i = 0; i < nums.size(); i++) {
            j = abs(nums[i]) - 1;
            if (nums[j] > 0) {
                nums[j] = -nums[j];
            }
        }

        // O(n)
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                v.push_back(i + 1);
            }
        }
        return v;
    }

    // O(n)
    vector<int> findDisappearedNumbersOld(vector<int>& nums) {

        // O(n)
        std::set<int> all_nums;
        for (int i = 1; i <= nums.size(); i++) {
            all_nums.insert(i);
        }

        // O(n)
        std::set<int> our_nums;
        for (int i = 0; i < nums.size(); i++) {
            our_nums.insert(nums[i]);
        }
        std::set<int> diff;
        
        // O(n)
        std::set_difference(all_nums.begin(), all_nums.end(),
                            our_nums.begin(), our_nums.end(),
                            std::inserter(diff, diff.end()));
        // O(n)
        std::vector<int> v;
        for (std::set<int>::iterator it = diff.begin(); it != diff.end(); ++it) {
            v.push_back(*it);
        }
        return v;
    }
};