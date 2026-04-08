/*
 * @lc app=leetcode id=1972517113 lang=cpp
 *
 * NextGreaterElementIi
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n);
        stack<int>stk;
        for(int i=2*n-1;i>=0;i--){
            while(!stk.empty()&&stk.top()<=nums[i%n]){
                stk.pop();
            }
            if(i<n){
                nge[i]=stk.empty()?-1:stk.top();
            }
            stk.push(nums[i%n]);
        }
        return nge;
    }
};