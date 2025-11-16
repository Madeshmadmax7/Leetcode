/*
 * @lc app=leetcode id=1831314806 lang=cpp
 *
 * NumberOfSubstringsWithOnly1s
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numSub(string s) {
        int cnt = 0, total = 0, mod = 1e9 + 7;
        for (char a : s) {
            if (a == '1') {
                cnt++;
            } else {
                cnt = 0;
            }
            total = (total + cnt) % mod;
        }
        return total;
    }
};