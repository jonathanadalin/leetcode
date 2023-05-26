class Solution {
public:
    void generateCombinations(string s, int open, int close, vector<string> &v) {
        if (open == 0 && close == 0) {
            // There's no parenthesis left to add.
            v.push_back(s);
        }
        if (open > 0) {
            s.append("(");
            generateCombinations(s, open - 1, close + 1, v);
            // We need to reset the string before entering the next if statement.
            s = s.substr(0, s.length() - 1);
        }
        if (close > 0) {
            s.append(")");
            generateCombinations(s, open, close - 1, v);
        }
    }
    // O(size of v)
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        generateCombinations(s, n, 0, v);
        return v;
    }
};