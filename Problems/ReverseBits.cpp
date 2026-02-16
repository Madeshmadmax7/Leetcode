/*
 * @lc app=leetcode id=1921081723 lang=cpp
 *
 * ReverseBits
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int reverseBits(int n) {
        
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            int num = (1 << i);
            if( n&num)
            {
                int res = (1<< (31-i));
                ans |=res;
            }
        }
        return ans;
    }
};