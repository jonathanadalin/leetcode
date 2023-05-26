class Solution {
public:
    // O(n^2) - Nested insert is expensive.
    // Explanation
    // The algorithm can be broken down in two parts.
    // 1. Sort the input vector by decreasing height, h, but within the same
    //    height, increasing number of people in front with GOE height, k.
    // 2. Starting with the first sorted values, we can insert them into <res>
    //    based on k because the elements already in <res> are of GOE height.
    //    The k property of elements already in <res> is respected by the newly
    //    inserted elements because:
    //      a. The smaller ones won't break this property
    //      b. The GOE ones are inserted after because of the sort in step 1.
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int> &v1, const vector<int> &v2) {
            return (v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]));                 
        };
        sort(people.begin(), people.end(), comp);  // O(nlog(n))     
        vector<vector<int>> res;
        for (auto& p : people)                     // O(n^2) - Nested operations
            res.insert(res.begin() + p[1], p);     // O(n)
        return res;
    }
};