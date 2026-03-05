/*
 * @lc app=leetcode id=1938884543 lang=cpp
 *
 * SpecialPositionsInABinaryMatrix
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int ct=0;
        for(int i=0;i<rows;i++){
            int r1=0;
            int col=-1;
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1){
                    r1++;
                    col=j;
                }
            }
            if(r1==1){
                int c1=0;
                for(int k=0;k<rows;k++){
                    if(mat[k][col]==1){
                        c1++;
                    }
                }
                if(c1==1){
                    ct++;
                }
            }
        }
        return ct;
    }
};
