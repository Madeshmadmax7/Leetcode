/*
 * @lc app=leetcode id=1984157275 lang=cpp
 *
 * MinimizeHammingDistanceAfterSwapOperations
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void dfs(int st,vector<vector<int>>&adj,vector<int>&vis,vector<int>&comp){
        vis[st]=1;
        comp.push_back(st);
        for(auto x:adj[st]){
            if(!vis[x]){
                dfs(x,adj,vis,comp);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>>adj(n);
        for(auto &x:allowedSwaps){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        int mism=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>comp;
                dfs(i,adj,vis,comp);
                unordered_map<int,int>freq;
                for(auto x:comp){
                    freq[source[x]]++;
                }
                for(int idx:comp){
                    if(freq[target[idx]]>0){
                        freq[target[idx]]--;
                    }
                    else{
                        mism++;
                    }
                }
            }
        }
        return mism;
    }
};