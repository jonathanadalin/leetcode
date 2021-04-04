class Solution {
public:
    
    void populateMap(map<char, int> &m, const string p) {
       for (int i = 0; i < p.length(); i++) {
           if (m.find(p[i]) != m.end()) {
                m[p[i]]++;
           } else {
                m.insert(std::pair<char, int>(p[i], 0));
           }
       } 
    }
    
    void copyMap(map<char, int> &pm, map<char, int> &wm) {
        for (map<char, int>::iterator it = pm.begin(); it != pm.end(); it++) {
            wm.insert(pair<char, int>((*it).first,(*it).second));
        }
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s.length() < p.length()) {
            return v;
        }
        map<char, int> populated_map;
        map<char, int> working_map;
        bool last_set_pass = false;
        bool skip_expensive_op = false;
        populateMap(populated_map, p);  // O(p.length())
        
        // O(s.length() * p.length()) at worst
        for (int i = 0; i < s.length() - p.length() + 1; i++) {
                
            // We don't need to check all the whole string if the last window
            // passed. We're good if the newest element is the same as the one
            // we stopped looking at.
            if (last_set_pass) {
                skip_expensive_op = true;
                if (s[p.length() + i - 1] == s[i - 1]) {
                    v.push_back(i);
                } else {
                    last_set_pass = false;
                }
            }
            
            if (!skip_expensive_op) {
                copyMap(populated_map, working_map);
                // O(p.length())
                for (int j = i; j < i + p.length(); j++) {
                    
                    if (working_map.find(s[j]) != working_map.end()) {
                        if (working_map[s[j]] > 0) {
                            working_map[s[j]]--;  
                        } else {
                            working_map.erase(s[j]);
                        }        
                    } else {
                        // If the element isn't part of <p>, then jump so that
                        // element is no longer scanned.
                        if (populated_map.find(s[j]) == populated_map.end()) {
                            i = j; 
                            break;
                        }       
                    }
                }
                if (working_map.size() == 0) {
                    v.push_back(i);
                    last_set_pass = true;
                } else {
                    last_set_pass = false;
                }
                working_map.clear();
            }
            skip_expensive_op = false;
        }
        return v;
    }

};