/*
 * @lc app=leetcode id=1968434779 lang=cpp
 *
 * CombinationSumIi
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void comb(vector<int>&temp,vector<vector<int>>&res,vector<int>&candidates,int target,int ind){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        if(ind>candidates.size()-1) return;
        for(int j=ind;j<candidates.size();j++){
            if(j>ind && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            temp.push_back(candidates[j]);
            comb(temp,res,candidates,target-candidates[j],j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>res;
        comb(temp,res,candidates,target,0);
        return res;
    }
};