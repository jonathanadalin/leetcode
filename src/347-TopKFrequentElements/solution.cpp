class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            auto it = m.find(num);
            if (it == m.end()) {
                m.insert(make_pair(num, 0));
            } else {
                it->second++;
            }
        }
        vector<pair<int, int>> freqs;
        for (auto it = m.begin(); it != m.end(); ++it) {
            freqs.push_back(*it);
        }
        auto comp = [](pair<int, int> freq1, pair<int, int> freq2) {
            return freq1.second > freq2.second;
        };
        sort(freqs.begin(), freqs.end(), comp);
        vector<int> res;
        for (int i = 0; i < k && i < freqs.size(); i++) {
            res.push_back(freqs[i].first);
        }
        return res;
    }
};