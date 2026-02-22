/*
 * @lc app=leetcode id=1927535600 lang=cpp
 *
 * BinaryGap
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int binaryGap(int n) {
        vector<int> a(32);
        int t = 0;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) != 0)
                a[t++] = i;
        }
        int ans = 0;
        for (int i = 0; i < t - 1; i++) {
            ans = max(ans, a[i + 1] - a[i]);
        }
        return ans;
    }
};