/*
 * @lc app=leetcode id=1836877370 lang=cpp
 *
 * FindMinimumOperationsToMakeAllElementsDivisibleByThree
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if (num % 3 != 0) res++;
        }
        return res;
    }
};