class Solution {
public:
    // O(nlog(n)) - Sort bottlenecking algorithm.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // We'll use an unordered_map to keep track of the count of each
        // value because its operations are O(1). We get O(n) for the loop.
        unordered_map<int, int> m;
        for (int num : nums) {
            auto it = m.find(num);
            if (it == m.end()) {
                m.insert(make_pair(num, 0));
            } else {
                it->second++;
            }
        }
        // We need to move those values to a vector so we can sort
        // by frequency. O(n) for the transfer to the vector.
        vector<pair<int, int>> freqs;
        for (auto it = m.begin(); it != m.end(); ++it) {
            freqs.push_back(*it);
        }
        // This sort is the algorithm bottleneck at O(nlog(n)).
        auto comp = [](pair<int, int> freq1, pair<int, int> freq2) {
            return freq1.second > freq2.second;
        };
        sort(freqs.begin(), freqs.end(), comp);
        vector<int> res;
        // Populating the result array is O(k) < O(n).
        for (int i = 0; i < k && i < freqs.size(); i++) {
            res.push_back(freqs[i].first);
        }
        return res;
    }
};