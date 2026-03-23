/*
 * @lc app=leetcode id=1956721193 lang=cpp
 *
 * MaximumNonNegativeProductInAMatrix
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long>> mindp(n, vector<long>(m));
        vector<vector<long>> maxdp(n, vector<long>(m));
        mindp[0][0] =  maxdp[0][0] = grid[0][0];
        
        for(int i = 1; i < n; i++){
            mindp[i][0] = grid[i][0] * mindp[i-1][0];
            maxdp[i][0] = grid[i][0] * maxdp[i-1][0];
        }

        for(int j = 1; j < m; j++){
            mindp[0][j] = grid[0][j] * mindp[0][j-1];
            maxdp[0][j] = grid[0][j] * maxdp[0][j-1];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                long p = grid[i][j] * mindp[i-1][j];
                long q = grid[i][j] * mindp[i][j-1];
                long r = grid[i][j] * maxdp[i-1][j];
                long s = grid[i][j] * maxdp[i][j-1];
                mindp[i][j] = min({p,q,r,s});
                maxdp[i][j] = max({p,q,r,s});

            }
        }

        long result = maxdp[n-1][m-1];
        return result < 0 ? -1 : result % (int)(1e9 + 7);
    }
};