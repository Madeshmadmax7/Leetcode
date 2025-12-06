/*
 * @lc app=leetcode id=1848085412 lang=cpp
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
    void countIslands(vector<vector<int>> &vis, vector<vector<char>>&grid, int r, int c){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> que;
        vis[r][c] = 1;
        que.push({r,c});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!que.empty()){
            int fr = que.front().first;
            int fc = que.front().second;
            que.pop();

            for(int k = 0; k < 4; k++){
                int nr = fr + dr[k];
                int nc = fc + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc] = 1;
                    que.push({nr,nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int c = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    countIslands(vis, grid, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};
