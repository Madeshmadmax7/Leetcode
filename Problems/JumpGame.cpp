/*
 * @lc app=leetcode id=1892396527 lang=cpp
 *
 * JumpGame
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return false;
        if(nums.size()==1) return true;
        int m=0;
        for(int i=0;i<nums.size();i++){
            if(i>m){
                return false;
            }
            m=max(m,i+nums[i]);
        }
        return true;
    }
};