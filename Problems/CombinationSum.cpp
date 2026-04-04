/*
 * @lc app=leetcode id=1968467729 lang=cpp
 *
 * CombinationSum
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void comb(vector<int>&temp,vector<vector<int>>&res,vector<int>&candidates,int target,int st){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        if(st>=candidates.size()) return;
        temp.push_back(candidates[st]);
        comb(temp,res,candidates,target-candidates[st],st);
        temp.pop_back();
        comb(temp,res,candidates,target,st+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        comb(temp,res,candidates,target,0);
        return res;
    }
};