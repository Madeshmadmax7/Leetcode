/*
 * @lc app=leetcode id=1968533625 lang=cpp
 *
 * NQueensIi
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,vector<vector<string>>&res){
        int n=board.size();
        int dr=row;
        int dc=col;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=dr;
        col=dc;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=dr;
        col=dc;
        while(row<n &&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&res,vector<string>&board,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,res)){
                board[row][col]='Q';
                solve(col+1,res,board,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        solve(0,res,board,n);
        return res.size();
    }
};