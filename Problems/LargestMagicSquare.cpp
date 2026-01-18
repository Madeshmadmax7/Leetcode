/*
 * @lc app=leetcode id=1888986953 lang=cpp
 *
 * LargestMagicSquare
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:

    bool isValid(vector<vector<int>>& grid, int i, int j, int k) {

        int sum = 0;

        for (int row=i; row<i+k; row++) {
            int curr = 0;
            for (int col=j; col<j+k; col++) {
                curr += grid[row][col];
            }
            if (row == i) {
                sum = curr;
            } else if (sum != curr) {
                return false;
            }
        }

        for (int col=j; col<j+k; col++) {
            int curr = 0;
            for (int row=i; row<i+k; row++) {
                curr += grid[row][col];
            }
            if (curr != sum) {
                return false;
            }
        }

        int curr = 0;
        for (int d=0; d<k; d++) {
            curr += grid[i+d][j+d];
        }
        if (curr != sum) {
            return false;
        }
        
        curr = 0;
        for (int d=0; d<k; d++) {
            curr += grid[i+d][j+k-1-d];
        }
        if (curr != sum) {
            return false;
        }

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int ans = 1;
        int m = grid.size();
        int n = grid[0].size();

        for (int k=2; k<=min(m, n); k++) {

            for (int i=0; i+k<=m; i++) {
                for (int j=0; j+k<=n; j++) {

                    if (isValid(grid, i, j, k)) {
                        ans = k;
                    }
                }
            }
        }

        return ans;
    }
};