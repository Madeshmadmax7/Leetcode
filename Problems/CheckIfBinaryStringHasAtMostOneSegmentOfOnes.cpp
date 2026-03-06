/*
 * @lc app=leetcode id=1939919604 lang=cpp
 *
 * CheckIfBinaryStringHasAtMostOneSegmentOfOnes
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=1;
        while(s[i++]=='1');
        while(i<s.size())
        {
            if(s[i]=='1')
            return false;
            i++;
        }
        return true;
        
    }
};