/*
 * @lc app=leetcode id=1892206677 lang=cpp
 *
 * ConstructTheMinimumBitwiseArrayIi
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] == 2){
                ans[i] = -1;
                continue;
            }
            for(int j = 1; j < 32; j++){
                if(!(nums[i]&(1<<j))){
                    ans[i] = (nums[i]&(~(1<<(j-1))));
                    break;
                }
            }
        }
        return ans;
    }
};