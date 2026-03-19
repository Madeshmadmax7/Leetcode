/*
 * @lc app=leetcode id=1953034101 lang=cpp
 *
 * HouseRobberIi
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int f(int n,vector<int>&dp,vector<int>&nums){
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n];
        if(n>1){
            pick+=f(n-2,dp,nums);
        }
        int notpick=0+f(n-1,dp,nums);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>nums1;
        vector<int>nums2;
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        vector<int>dp1(nums1.size(),-1);
        vector<int>dp2(nums2.size(),-1);
        return max(f(nums1.size()-1,dp1,nums1),f(nums2.size()-1,dp2,nums2));
    }
};