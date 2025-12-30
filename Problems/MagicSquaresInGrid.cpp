/*
 * @lc app=leetcode id=1869066843 lang=cpp
 *
 * MagicSquaresInGrid
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c) {
        set<int> st;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int num = grid[i][j];
                if (num <= 0 || num > 9 || st.find(num) != st.end()) {
                    return false;
                }
                st.insert(num);
            }
        }

        int diag1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];

        int diag2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (diag1 != diag2)
            return false;

        for (int i = r; i < r + 3; i++) {
            if (diag1 != grid[i][c] + grid[i][c + 1] + grid[i][c + 2])
                return false;
        }

        for (int i = c; i < c + 3; i++) {
            if (diag1 != grid[r][i] + grid[r + 1][i] + grid[r + 2][i])
                return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (row < 3 || col < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (check(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};