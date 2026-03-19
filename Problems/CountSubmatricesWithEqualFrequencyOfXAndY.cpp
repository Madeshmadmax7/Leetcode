/*
 * @lc app=leetcode id=1953128099 lang=cpp
 *
 * CountSubmatricesWithEqualFrequencyOfXAndY
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>sumxy(m,{0,0});
        int x=0, y=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            x = 0;
            y = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'X'){
                    sumxy[j].first += 1;
                }else if(grid[i][j] == 'Y'){
                    sumxy[j].second += 1;
                }
                x += sumxy[j].first ;
                y += sumxy[j].second;
                if(x >= 1 && (x == y))ans++;
            }
        }
        return ans;

    }
};