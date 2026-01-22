/*
 * @lc app=leetcode id=1893267292 lang=cpp
 *
 * UniquePathsIi
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int func(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j) {
        if (i<0||j<0) return 0;
        if (arr[i][j]==1) return 0;
        if (i==0 && j==0) return 1;

        if (dp[i][j]!=-1) return dp[i][j];

        int up=func(arr,dp,i-1,j);
        int left=func(arr,dp,i,j-1);

        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return func(obstacleGrid,dp,n-1,m-1);
    }
};
