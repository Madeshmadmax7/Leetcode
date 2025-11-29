/*
 * @lc app=leetcode id=1842452277 lang=cpp
 *
 * MinimumOperationsToMakeArraySumDivisibleByK
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0)%k;
    }
};