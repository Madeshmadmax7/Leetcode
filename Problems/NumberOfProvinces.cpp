/*
 * @lc app=leetcode id=1994962341 lang=cpp
 *
 * NumberOfProvinces
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void dfs(vector<vector<int>>&isconnected,vector<int>&vis,int st){
        vis[st]=1;
        for(int i=0;i<isconnected.size();i++){
            if(isconnected[st][i]==1&&vis[i]!=1){
                vis[i]=1;
                dfs(isconnected,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        int ct=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isconnected,vis,i);
                ct++;
            }
        }
        return ct;
    }
};