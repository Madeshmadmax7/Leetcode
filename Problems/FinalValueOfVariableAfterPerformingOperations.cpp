/*
 * @lc app=leetcode id=1806858755 lang=cpp
 *
 * FinalValueOfVariableAfterPerformingOperations
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto& op: operations)
            x+=(op[1]=='+')?1:-1;
        return x;
    }
};