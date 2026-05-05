/*
 * @lc app=leetcode id=1996198206 lang=cpp
 *
 * WordSearch
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
    bool dfs(vector<vector<char>>&board,string word,vector<vector<int>>&vis,int i,int j,int n,int m,int ind){
        if(ind==word.size()-1) return true;

        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=dr[k]+i;
            int nc=dc[k]+j;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&board[nr][nc]==word[ind+1]){
                if(dfs(board,word,vis,nr,nc,n,m,ind+1)){
                    return true;
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,vis,i,j,n,m,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};