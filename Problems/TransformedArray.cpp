/*
 * @lc app=leetcode id=1909248197 lang=cpp
 *
 * TransformedArray
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                result[i] = nums[(i+nums[i])%n];
            }
            else if(nums[i]<0){
                result[i] = nums[(i-abs(nums[i]))%n < 0 ? (i-abs(nums[i]))%n + n : (i-abs(nums[i]))%n];
            }
            else{
                result[i] = 0;
            }
        }

        return result;
    }
};