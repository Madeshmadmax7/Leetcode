/*
 * @lc app=leetcode id=1940966549 lang=cpp
 *
 * MinimumNumberOfFlipsToMakeTheBinaryStringAlternating
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int flag = 0;
        int cost = 0;

        for (int i = 0; i < n; i++) {
            int curr = s[i] - '0';

            if (curr != flag)
                cost++;

            flag ^= 1;
        }

        int result = min(cost, n - cost);

        for (int i = 0; i < n - 1; i++) {
            int curr = s[i] - '0';

            if (curr != (i % 2))
                cost--;

            if (curr != ((n + i) % 2))
                cost++;

            result = min(result, min(cost, n - cost));
        }
        return result;
    }
};