/*
 * @lc app=leetcode id=1836018643 lang=cpp
 *
 * UniqueLength3PalindromicSubsequences
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int> firstOcc;
        map<char, int> lastOcc;
        for (int i = 0; i < (int)s.size(); i++) {
            lastOcc[s[i]] = i;
            if (firstOcc.find(s[i]) == firstOcc.end()) {
                firstOcc[s[i]] = i;
            }
        }

        int ans = 0;
        for (auto [C, L] : firstOcc) {
            int R = lastOcc[C];
            set<char> middleChars;
            for (int i = L + 1; i < R; i++) {
                middleChars.insert(s[i]);
            }
            ans += (int)middleChars.size();
        }
        return ans;
    }
};