/*
 * @lc app=leetcode id=1923278734 lang=cpp
 *
 * BinaryNumberWithAlternatingBits
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n^(n>>1);
        return (x&(x+1))==0;
    }
};