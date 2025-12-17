/*
 * @lc app=leetcode id=1858022200 lang=cpp
 *
 * BestTimeToBuyAndSellStockV
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    typedef long long ll;
    ll dp[1000][2][501][3];
    ll solve(int i ,int flag ,int k  , vector<int>& nums ,int prev){
        if(k>0 && i==nums.size()-1 && prev==1) return -nums[i];
        if(i>=nums.size() || k<=0){
            if(prev==0) return 0;
            else if(prev==-1) return 0;
            else return -nums[nums.size()-1];
        }

        if(dp[i][flag][k][prev+1]!=-1) return dp[i][flag][k][prev+1];
        if(flag){
            if(prev==0){
                 ll sell = nums[i] + solve(i+1 , !flag , k-1 , nums ,-1);
                 ll notSell = solve(i+1 ,flag ,k ,nums  , prev);
                 return  dp[i][flag][k][prev+1] = max(sell , notSell);
            }
            else{
                 ll sell = -nums[i] + solve(i+1 , !flag ,k-1 ,nums , -1);
                 ll notSell = solve(i+1 ,flag ,k ,nums , prev);

                 return dp[i][flag][k][prev+1] = max(sell ,notSell);
            }
        }
        else{
             ll normal = -nums[i] + solve(i+1  , !flag ,k ,nums , 0);
             ll shortSelling = nums[i] + solve(i+1 ,!flag ,k ,nums ,1);

             ll notbuy = solve(i+1 , flag , k,  nums,-1);
             
             return dp[i][flag][k][prev+1] = max({normal , shortSelling  , notbuy});
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1 ,sizeof(dp));
        return solve(0 , 0, k ,prices,-1);
    }
};