/*
 * @lc app=leetcode id=1968418898 lang=cpp
 *
 * Combinations
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void com(vector<int>&arr,vector<vector<int>>&res,int i,int n,int k){
        if(arr.size()==k){
            res.push_back(arr);
            return;
        }
        if(i>n) return;
        arr.push_back(i);
        com(arr,res,i+1,n,k);
        arr.pop_back();
        com(arr,res,i+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<vector<int>>res;
        com(arr,res,1,n,k);
        return res;
    }
};