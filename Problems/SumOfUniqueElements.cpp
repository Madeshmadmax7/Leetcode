/*
 * @lc app=leetcode id=1892710464 lang=cpp
 *
 * SumOfUniqueElements
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int last=nums[n-1];
        vector<int>arr(last+1,0);
        for(int num:nums){
            arr[num]++;
        }
        int sum=0;
        for(int i=0;i<=last;i++){
            if(arr[i]==1){
                sum+=i;
            }
        }
        return sum;
    }
};