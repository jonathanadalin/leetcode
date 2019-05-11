class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return num;
            }
        }
        return -1;
    }
};