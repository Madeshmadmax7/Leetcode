/*
 * @lc app=leetcode id=1890449209 lang=cpp
 *
 * SurroundedRegions
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
private:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(vector<vector<char>> &board,vector<vector<int>>&vis,int r,int c){
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&board[nr][nc]=='O'&&!vis[nr][nc]){
                dfs(board,vis,nr,nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'&&!vis[0][j]){
                dfs(board,vis,0,j);
            }
            if(board[n-1][j]=='O'&&!vis[n-1][j]){
                dfs(board,vis,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&&!vis[i][0]){
                dfs(board,vis,i,0);
            }
            if(board[i][m-1]=='O'&&!vis[i][m-1]){
                dfs(board,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};