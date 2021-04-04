class Solution {
    
public:
    
    // O(strs.size() * str.length()*log(str.length()));
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        // O(strs.size() * str.length()*log(str.length()));
        for (const string str : strs) {
            string key = str;
            sort(key.begin(), key.end());  // nlog(n)
            anagrams[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto anagram : anagrams) {
            res.push_back((anagram).second);
        }
        return res;
    }
    
};