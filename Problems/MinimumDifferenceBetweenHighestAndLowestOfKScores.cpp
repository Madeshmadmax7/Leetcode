/*
 * @lc app=leetcode id=1896612220 lang=cpp
 *
 * MinimumDifferenceBetweenHighestAndLowestOfKScores
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = i+k-1;
        int maxi = INT_MAX;
        while(j<n){
            maxi = min(maxi, nums[j]-nums[i]);
            i++;
            j++;
        }
        return maxi;
    }
};