/*
 * @lc app=leetcode id=1890455832 lang=cpp
 *
 * NumberOfEnclaves
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
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int r,int c){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&!vis[nr][nc]){
                dfs(grid,vis,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1&&!vis[0][j]){
                dfs(grid,vis,0,j);
            }
            if(grid[n-1][j]==1&&!vis[n-1][j]){
                dfs(grid,vis,n-1,j);
            }

        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1&&!vis[i][0]){
                dfs(grid,vis,i,0);
            }
            if(grid[i][m-1]==1&&!vis[i][m-1]){
                dfs(grid,vis,i,m-1);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};