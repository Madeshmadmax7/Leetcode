/*
 * @lc app=leetcode id=1999840289 lang=cpp
 *
 * MaximumNumberOfJumpsToReachTheLastIndex
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == -1) continue;

            for(int j = i + 1; j < n; j++) {
                long long diff = 1LL * nums[j] - nums[i];

                if(-target <= diff && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};