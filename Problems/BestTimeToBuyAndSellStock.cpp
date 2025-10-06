/*
 * @lc app=leetcode id=1793274778 lang=cpp
 *
 * BestTimeToBuyAndSellStock
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=0;
        for(int num:prices){
            min_price=min(num,min_price);
            int profit=num-min_price;
            max_profit=max(profit,max_profit);
        }
        return max_profit;
    }
};