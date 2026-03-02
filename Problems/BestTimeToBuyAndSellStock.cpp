/*
 * @lc app=leetcode id=1935729503 lang=cpp
 *
 * BestTimeToBuyAndSellStock
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int num:prices){
            minPrice=min(minPrice,num);
            maxProfit=max(maxProfit,num-minPrice);
        }
        return maxProfit;
    }
};