/*
 * @lc app=leetcode id=1991018254 lang=cpp
 *
 * SubarraySumEqualsK
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ct=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    ct++;
                }
            }
        }
        return ct;
    }
};