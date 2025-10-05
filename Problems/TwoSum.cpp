/*
 * @lc app=leetcode id=1792342912 lang=cpp
 *
 * TwoSum
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x1,x2;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    x1=i;
                    x2=j;
                    break;
                }
            }
        }
        return {x1,x2};
    }
};