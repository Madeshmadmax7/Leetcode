/*
 * @lc app=leetcode id=1958810640 lang=cpp
 *
 * EqualSumGridPartitionI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        long long tot=0;
        for(auto &row:grid){
            for(int x:row){
                tot+=x;
            }
        }
        if(tot%2) return false;
        long long target=tot/2,sum=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            if(sum==target) return true;
        }
        sum=0;
        for(int j=0;j<n-1;j++){
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
            }
            if(sum==target) return true;
        }
        return false;
    }
};