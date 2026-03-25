/*
 * @lc app=leetcode id=1958793018 lang=cpp
 *
 * NumberOfIslands
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int n,int m){
        vis[i][j]=1;
        queue<pair<int,int>>que;
        que.push({i,j});
        while(!que.empty()){
            int fr=que.front().first;
            int fc=que.front().second;
            que.pop();
            for(int k=0;k<4;k++){
                int nr=dr[k]+fr;
                int nc=dc[k]+fc;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]=='1'&&!vis[nr][nc]){
                    que.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    bfs(grid,vis,i,j,n,m);
                    c++;
                }
            }
        }
        return c;
    }
};