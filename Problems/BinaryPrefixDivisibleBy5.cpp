/*
 * @lc app=leetcode id=1838497507 lang=cpp
 *
 * BinaryPrefixDivisibleBy5
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> res;

        for (auto& n : nums) {
            val = ((val << 1) + n) % 5;
            res.push_back(val == 0);
        }

        return res;
    }
};
