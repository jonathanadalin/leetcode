class Solution {
public:
    // O(size of matrix)
    void rotate(vector<vector<int>>& matrix) {
        // A clockwise rotation is simply:
        //   1. Horizontal reflexion followed by
        //   2. Diagonal reflexion
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};