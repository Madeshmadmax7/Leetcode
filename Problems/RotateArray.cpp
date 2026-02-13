/*
 * @lc app=leetcode id=1918124768 lang=cpp
 *
 * RotateArray
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            int ni=(i+k)%n;
            temp[ni]=nums[i];
        }
        nums=temp;
    }
};