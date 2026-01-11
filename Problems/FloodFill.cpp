/*
 * @lc app=leetcode id=1881575548 lang=cpp
 *
 * FloodFill
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void bfs(vector<vector<int>>&copy,vector<vector<int>>&img,int sr,int sc,int init,int newc){
        copy[sr][sc]=newc;
        int n=img.size();
        int m=img[0].size();
        for(int i=0;i<4;i++){
            int nr=dr[i]+sr;
            int nc=dc[i]+sc;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&img[nr][nc]==init&&copy[nr][nc]!=newc){
                bfs(copy,img,nr,nc,init,newc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>copy=image;
        int init=image[sr][sc];
        bfs(copy,image,sr,sc,init,color);
        return copy;
    }
};