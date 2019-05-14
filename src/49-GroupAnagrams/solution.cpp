class Solution {
    
private:
    
    bool isAnagram(const string& a, const string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        map<char, int> freq;
        for (char c : a) {
            auto it = freq.find(c);
            if (it == freq.end()) {
                freq.insert(make_pair(c, 1));
            } else {
                (*it).second++;
            }
        }
        for (char c : b) {
            auto it = freq.find(c);
            if (it == freq.end()) {
                return false;
            } else {
                if ((*it).second == 0) {
                    return false;
                }
                (*it).second--;
            }
        }
        return true;
    }
    
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size() < 1) {
            return res;
        }
        bool added = false;
        for (string str : strs) {
            for (auto &group : res) {
                if (isAnagram(group[0], str)) {
                    group.push_back(str);
                    added = true;
                    break;
                }
            }
            if (!added) {
                vector<string> temp;
                temp.push_back(str);
                res.push_back(temp);
            }
            added = false;
        }
        return res;       
    }
};