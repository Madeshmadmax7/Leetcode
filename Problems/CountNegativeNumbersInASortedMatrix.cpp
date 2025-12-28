/*
 * @lc app=leetcode id=1867533022 lang=cpp
 *
 * CountNegativeNumbersInASortedMatrix
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int count = 0;
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                count += m - j;
                i--;
            } else {
                j++;
            }
        }

        return count;
    }
};