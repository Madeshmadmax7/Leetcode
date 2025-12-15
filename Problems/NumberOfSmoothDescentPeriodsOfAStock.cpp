/*
 * @lc app=leetcode id=1856124255 lang=cpp
 *
 * NumberOfSmoothDescentPeriodsOfAStock
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        long long cnt = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            ans += cnt;
        }

        return ans;
    }
};