/*
 * @lc app=leetcode id=1893229050 lang=cpp
 *
 * UniquePaths
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int func(vector<vector<int>>&dp,int i,int j){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=func(dp,i-1,j);
        int down=func(dp,i,j-1);
        return dp[i][j]=up+down;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=func(dp,n-1,m-1);
        return res;
    }
};