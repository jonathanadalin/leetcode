class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> v;
        int days_to_wait;
        for (int i = 0; i < T.size(); i++) {
            days_to_wait = 0;
            for (int j = i + 1; j <= T.size(); j++) {
                if (j == T.size()) {
                    v.push_back(0);
                } else {
                    days_to_wait++;
                    if (T[i] < T[j]) {
                        v.push_back(days_to_wait);
                        j = T.size();
                    }
                }
            }
        }
        return v;
    }
};