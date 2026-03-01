/*
 * @lc app=leetcode id=1934444541 lang=cpp
 *
 * ClimbingStairs
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int solve(vector<int>&dp,int n){
        if(n==0||n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int res=solve(dp,n);
        return res;
    }
};