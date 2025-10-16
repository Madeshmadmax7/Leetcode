/*
 * @lc app=leetcode id=1803347248 lang=cpp
 *
 * SmallestMissingNonNegativeIntegerAfterOperations
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
       unordered_map<int,int>fr;
        int r,mx=0;
       for(int x:nums) {
          r=((x%value)+value)%value;
          fr[r]++;
       }
       while(true){
            r=mx%value;
            if(fr[r]>0)
              fr[r]--;
            else break;
            mx++;
        }
        return mx; 
    }
};