/*
 * @lc app=leetcode id=1951172164 lang=cpp
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
    void dfs(int st,vector<vector<int>>&adj,vector<int>&vis,int n){
        vis[st]=1;
        for(int i=0;i<n;i++){
            if(adj[st][i]==1&&!vis[i]){
                dfs(i,adj,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        int ct=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ct++;
                dfs(i,adj,vis,n);
            }
        }
        return ct;
    }
};