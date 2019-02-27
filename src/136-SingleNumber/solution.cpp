#include <map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, bool> map;
        int sum = 0;     
        for (const int &i : nums) {
            if (map[i]) {
                sum -= i;  // The value is repeated
            }
            else {
                map.erase(i);  // Checking its value in the map creates it.
                map.insert(std::pair(i, true));
                sum += i;
            }
        }
        return sum;
    }
};