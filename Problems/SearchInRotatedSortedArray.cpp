/*
 * @lc app=leetcode id=1969275055 lang=cpp
 *
 * SearchInRotatedSortedArray
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};