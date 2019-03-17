class Solution {
public:
    
    void populateSet(unordered_set<char> &set, string p) {
       for (int i = 0; i < p.length(); i++) {
           set.insert(p[i]);
       } 
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s.length() < p.length()) {
            return v;
        }
        unordered_set<char> set;
        for (int i = 0; i < s.length() - p.length() + 1; i++) {
            populateSet(set, p);
            for (int j = i; j < p.length() + i; j++) {
                set.erase(s[j]);
            }
            if (set.size() == 0) {
                v.push_back(i);
            }
            set.clear();
        }
        return v;
    }

};