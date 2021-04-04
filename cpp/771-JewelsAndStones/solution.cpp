#include <map>

class Solution {
public:
    // Complexity: Linear - O(J.length() + S.length())
    int numJewelsInStones(string J, string S) {
        std::map<char,int> map; 
        for (char c : J) {
            map.insert(std::pair(c, true));  // O(1)
        }
        int count = 0;
        for (char c : S) {
            if (map[c])  // O(1)
                count++;
        }
        return count;
    }
};