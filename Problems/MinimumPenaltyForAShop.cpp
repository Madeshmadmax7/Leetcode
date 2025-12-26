/*
 * @lc app=leetcode id=1865815117 lang=cpp
 *
 * MinimumPenaltyForAShop
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0,penalty = INT_MAX,count = 0;
        int cy = 0,cn = 0;
        for(auto it :  customers){
            if(it == 'Y') cy++;
        }
        for(auto it : customers){
            if(cn + cy < penalty){
                penalty = cn + cy;
                ans = count;
            }
            if(it == 'N') cn++;
            else cy--;
            count++;
        }
        if(cn < penalty){
            ans = count;
        }
        return ans;
    }
};