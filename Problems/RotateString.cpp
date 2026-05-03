/*
 * @lc app=leetcode id=1994291361 lang=cpp
 *
 * RotateString
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool rotateString(string& s, string& goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};