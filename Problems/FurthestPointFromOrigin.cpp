/*
 * @lc app=leetcode id=1987016791 lang=cpp
 *
 * FurthestPointFromOrigin
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x=0, r=0;
        for(char c: moves){
            x+=(c=='R')-(c=='L');
            r+=c=='_';
        }
        return abs(x)+r;
    }
};