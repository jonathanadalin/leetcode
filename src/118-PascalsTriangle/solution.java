class Solution {
    // O(n + n-1 + n-2 + ... + 1) = O((n^2 + n) / 2)
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList();
        for (int row = 0; row < numRows; row++) {
            triangle.add(new ArrayList());
            for (int i = 0; i < row + 1; i++) {
                if (i == 0 || i == row) {
                    triangle.get(row).add(1);
                } else {
                    triangle.get(row).add(triangle.get(row - 1).get(i - 1) +
                                          triangle.get(row - 1).get(i));
                }
            }
        }
        return triangle;
    }
}