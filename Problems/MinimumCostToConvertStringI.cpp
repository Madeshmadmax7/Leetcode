/*
 * @lc app=leetcode id=1901070180 lang=cpp
 *
 * MinimumCostToConvertStringI
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define MAX_VAL 100000000

class Solution {
public:
    using ll=long long;
    void floydWarshall(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int inter = 0; inter < n; inter++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][inter] == MAX_VAL || grid[inter][j] == MAX_VAL)
                        continue;
                    grid[i][j] =
                        min(grid[i][j], grid[i][inter] + grid[inter][j]);
                }
            }
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> grid(26, vector<int>(26, MAX_VAL));
        int n = source.size(), m = original.size();
        for (int i = 0; i < m; i++) {
            int x = original[i] - 'a', y = changed[i] - 'a';
            grid[x][y] = min(grid[x][y], cost[i]);
        }

        for (int i = 0; i < 26; i++) {
            grid[i][i] = 0;
        }

        floydWarshall(grid);
        ll ans=0;
        for(int i=0;i<n;i++){
            int x=source[i]-'a',y=target[i]-'a';
            if(grid[x][y]==MAX_VAL){
                return -1;
            }
            ans+=grid[x][y];
        }
        return ans;
    }
};