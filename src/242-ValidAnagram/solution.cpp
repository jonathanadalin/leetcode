#include <map>

class Solution {
public:
    
    // O(1)
    bool contains(std::map<char, int> &m, char c) {
        return m.find(c) != m.end();
    }
    
    // O(s.length() + t.length())
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }
        
        std::map<char, int> m;
        for (char c : s) {
            if (!contains(m, c)) {
                m.insert(std::pair<char, int>(c, 1));
            } else {
                m[c]++;
            }
        }
        for (char c : t) {
            if (!contains(m, c)) {
                return false;
            } else {
                if (m[c] < 1) {
                    return false;
                } else {
                    m[c]--;
                }
            }
        }
        return true;
    }
};