class Solution {
public:
    
    void populateSet(map<char, int> &m, const string p) {
       for (int i = 0; i < p.length(); i++) {
           if (m.find(p[i]) != m.end()) {
                m[p[i]]++;
           } else {
                m.insert(std::pair<char, int>(p[i],0));
           }
       } 
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s.length() < p.length()) {
            return v;
        }
        map<char, int> m;
        for (int i = 0; i < s.length() - p.length() + 1; i++) {
            populateSet(m, p);
            for (int j = i; j < p.length() + i; j++) {
                if (m.find(s[j]) != m.end()) {
                    if (m[s[j]] > 0) {
                        m[s[j]]--;  
                    } else {
                        m.erase(s[j]);
                    }        
                }
            }
            if (m.size() == 0) {
                v.push_back(i);
            }
            m.clear();
        }
        return v;
    }

};