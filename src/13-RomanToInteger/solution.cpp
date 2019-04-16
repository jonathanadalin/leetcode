class Solution {
public:
    
    int toInt(char c) {
        switch (c) {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return 0;
        }
    }
    
    int romanToInt(string s) {
        int sum = 0;
        int i;
        for (i = 0; i < s.length() - 1; i++) {
            if (toInt(s[i]) < toInt(s[i + 1])) {
                sum += toInt(s[i + 1]) - toInt(s[i]);
                i++;
            } else {
                sum += toInt(s[i]);
            }
        }
        if (i < s.length()) {
            sum += toInt(s[s.length() - 1]);
        }
        return sum;
    }

};