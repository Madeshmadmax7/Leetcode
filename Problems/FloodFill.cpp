/*
 * @lc app=leetcode id=1994996958 lang=cpp
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dr[4]={0,1,0,-1};
        int dc[4]={-1,0,1,0};
        int ic=image[sr][sc];
        if(ic==color) return image;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>que;
        que.push({sr,sc});
        image[sr][sc]=color;
        while(!que.empty()){
            int fr=que.front().first;
            int fc=que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
                int nr=fr+dr[i];
                int nc=fc+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==ic){
                    image[nr][nc]=color;
                    que.push({nr,nc});
                }
            }
        }
        return image;
    }
};