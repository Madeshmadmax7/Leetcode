/*
 * @lc app=leetcode id=1892312204 lang=cpp
 *
 * FrogJumpIi
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
};
