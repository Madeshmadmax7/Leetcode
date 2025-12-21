/*
 * @lc app=leetcode id=1861533074 lang=cpp
 *
 * DeleteColumnsToMakeSortedIi
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> sorted(n - 1, false);
        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool need = false;
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    need = true;
                    break;
                }
            }

            if (need) {
                ans++;
                continue;
            }
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return ans;
    }
};