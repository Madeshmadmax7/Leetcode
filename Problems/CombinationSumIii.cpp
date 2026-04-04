/*
 * @lc app=leetcode id=1968423480 lang=cpp
 *
 * CombinationSumIii
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void com(vector<int>&temp,vector<vector<int>>&res,int i,int k,int target){
        if(temp.size()==k&&target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        if(i>9) return;
        temp.push_back(i);
        com(temp,res,i+1,k,target-i);
        temp.pop_back();
        com(temp,res,i+1,k,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>res;
        com(temp,res,1,k,n);
        return res;
    }
};