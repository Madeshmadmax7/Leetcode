/*
 * @lc app=leetcode id=1994972773 lang=cpp
 *
 * NumberOfIslands
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j){
        int dr[4]={0,1,0,-1};
        int dc[4]={-1,0,1,0};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        que.push({i,j});
        while(!que.empty()){
            int fr=que.front().first;
            int fc=que.front().second;
            que.pop();
            for(int k=0;k<4;k++){
                int nr=fr+dr[k];
                int nc=fc+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    que.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ct=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    bfs(grid,vis,i,j);
                    ct++;
                }
            }
        }
        return ct;
    }
};