/*
 * @lc app=leetcode id=1874319864 lang=cpp
 *
 * FourDivisors
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int Total_sum = 0;
        for(int n: nums){
            int cnt = 0, sum = 0;
            for(int i = 1;i*i<=n;i++){
                if(n % i == 0){
                    cnt++;
                    sum += i;
                    if(i != n/i){
                        cnt++;
                        sum +=n/i;
                    }
                }
                if(cnt>4) break;
            }
            if(cnt == 4){
                Total_sum+=sum;
            }
        }
        return Total_sum;
    }
};