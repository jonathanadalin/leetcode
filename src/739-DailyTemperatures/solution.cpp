class Solution {
public:

    // O(n) - Single pass of T
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> days_to_wait(T.size(), 0);
        if (T.size() == 0) {
            return days_to_wait;
        }
        stack<int> indexes;
        for (int i = 0; i < T.size(); i++) {
            while(!indexes.empty() && T[i] > T[indexes.top()]) {
                int index = indexes.top();
                days_to_wait[index] = i - index;
                indexes.pop();
            }
            indexes.push(i);
        }
        return days_to_wait;
    }

    // O(n^2) - Nested for loop of T
    vector<int> dailyTemperatures_slow(vector<int>& T) {
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