/*
 * @lc app=leetcode id=1815138129 lang=cpp
 *
 * SmallestNumberWithAllSetBits
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int smallestNumber(int n) {
        while (n & (n + 1)) {
            n |= n + 1;
        }
        return n;
    }
};