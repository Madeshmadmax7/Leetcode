/*
 * @lc app=leetcode id=1930890009 lang=cpp
 *
 * SortIntegersByTheNumberOf1Bits
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> v(32);

        for (int n: arr) {
            int bit = __builtin_popcount(n);
            v[bit].push_back(n);
        }

        vector<int> ans;
        for (auto& vec: v) {
            sort(vec.begin(), vec.end());
            for (int n: vec) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};