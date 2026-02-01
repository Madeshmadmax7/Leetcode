/*
 * @lc app=leetcode id=1904477055 lang=cpp
 *
 * DivideAnArrayIntoSubarraysWithMinimumCostI
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1,nums.end());
        return nums[0]+nums[1]+nums[2];
    }
};