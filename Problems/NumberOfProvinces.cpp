/*
 * @lc app=leetcode id=1847749676 lang=cpp
 *
 * NumberOfProvinces
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void bfs(vector<int>& vis,vector<int> adjL[],int n){
        vis[n]=1;
        for(auto it: adjL[n]){
            if(!vis[it]){
                bfs(vis,adjL,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        int m = isConnected.size();
        vector<int> adjList[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1&&i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                bfs(vis,adjList,i);
            }
        }
        return c;
    }
};