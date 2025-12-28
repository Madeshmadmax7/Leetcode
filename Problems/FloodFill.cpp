/*
 * @lc app=leetcode id=1867726843 lang=cpp
 *
 * FloodFill
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
    void dfs(vector<vector<int>>& copy,vector<vector<int>>& image, int row, int col, int color,int initial){
        copy[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nr=dr[i]+row;
            int nc=dc[i]+col;
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initial && copy[nr][nc]!=color){
                dfs(copy,image,nr,nc,color,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> copy=image;
        int initial=image[sr][sc];
        dfs(copy,image,sr,sc,color,initial);
        return copy;
    }
};