/*
 * @lc app=leetcode id=1969277193 lang=cpp
 *
 * FindFirstAndLastPositionOfElementInSortedArray
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fp=-1,lp=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                fp=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                lp=i;
                break;
            }
        }
        return {fp,lp};
    }
};