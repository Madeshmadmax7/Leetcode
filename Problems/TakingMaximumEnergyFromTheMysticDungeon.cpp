/*
 * @lc app=leetcode id=1797328603 lang=cpp
 *
 * TakingMaximumEnergyFromTheMysticDungeon
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int ans = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + ((i + k < n) ? dp[i + k] : 0);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};