class Solution {
public:
    // O(n) - Only go through nums once
    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {
                v.push_back(1 + v[i/2]);
            } else {
                v.push_back(v[i/2]);
            }
        }
        return v;
    }
};