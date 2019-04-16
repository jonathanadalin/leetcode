#include <map>

class Solution {
public:
    
    bool contains(std::map<char, int> &m, char c) {
        // O(size of m)
        for (std::map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->first == c) {
                return true;
            }
        }
        return false;
    }
    
    // O(size of m * s.length() + size of m * s.length())
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