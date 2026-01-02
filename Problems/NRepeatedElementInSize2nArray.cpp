/*
 * @lc app=leetcode id=1872200429 lang=cpp
 *
 * NRepeatedElementInSize2nArray
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int k=1;k<=3;k++) {
                if(i+k<n && nums[i]==nums[i+k])
                    return nums[i];
            }
        }
        return 0;
    }
};