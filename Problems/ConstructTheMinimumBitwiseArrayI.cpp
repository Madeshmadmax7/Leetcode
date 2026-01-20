/*
 * @lc app=leetcode id=1891149393 lang=cpp
 *
 * ConstructTheMinimumBitwiseArrayI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 2) ans.push_back(-1);
            else
            {
                int x = ~nums[i];
                x = x ^ (x - 1);
                x = log2(x) - 1;
                x = pow(2, x);
                x = ~x;
                ans.push_back(nums[i] & x);
            }
        }
        return ans;    
    }
};