/*
 * @lc app=leetcode id=1935716998 lang=cpp
 *
 * HouseRobber
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int solve(int n,vector<int>&dp,vector<int>&nums){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+solve(n-2,dp,nums);
        int notpick=solve(n-1,dp,nums);
        return dp[n] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int res=solve(n-1,dp,nums);
        return res;
    }
};