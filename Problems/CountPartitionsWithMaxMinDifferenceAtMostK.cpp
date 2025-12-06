/*
 * @lc app=leetcode id=1848317383 lang=cpp
 *
 * CountPartitionsWithMaxMinDifferenceAtMostK
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        vector<int> P(n + 1);
        multiset<int> S;

        int l = 1;
        for (int r = 1; r <= n; r++) {
            S.insert(nums[r - 1]);

            while (*S.rbegin() - *S.begin() > k) {
                S.erase(S.find(nums[l - 1]));
                l++;
            }
            P[r] = l;
        }

        vector<long long> dp(n + 1), dpSum(n + 1);

        dp[0] = 1;
        dpSum[0] = 1;

        for (int r = 1; r <= n; r++) {
            int left = P[r] - 1;

            long long total = dpSum[r - 1];
            long long subtract = (left - 1 >= 0 ? dpSum[left - 1] : 0LL);

            dp[r] = (total - subtract + mod) % mod;
            dpSum[r] = (dpSum[r - 1] + dp[r]) % mod;
        }

        return dp[n];
    }
};